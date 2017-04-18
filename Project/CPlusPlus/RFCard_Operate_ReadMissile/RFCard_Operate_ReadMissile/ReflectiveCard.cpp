/**************************************************/
/**************************************************/
/************RFM2gͷ�ļ����궨��******************/
/**************************************************/
/**************************************************/
#if (defined(WIN32))
#include "rfm2g_windows.h"
#endif

#include <stdio.h>
#include <string.h>
#include "rfm2g_api.h"
#include <time.h>
#include "ReflectiveCard.h"
#if (defined(RFM2G_LINUX))

#ifdef CONFIG_DEVFS_FS
#define DEVICE_PREFIX   "/dev/rfm2g/"
#else
#define DEVICE_PREFIX   "/dev/rfm2g"
#endif

#define PROCFILE         "/proc/rfm2g"

#elif defined(RFM2G_VXWORKS)

#define DEVICE_PREFIX   "RFM2G_"

#elif defined(SOLARIS)

#define DEVICE_PREFIX   "/dev/rfm2g"

#elif defined(WIN32)

#define DEVICE_PREFIX   "\\\\.\\rfm2g"
#else

#error Please define DEVICE_PREFIX for your driver
#endif

#define RFCARD_TRANS_MODE_ADDR 0x0010  //�����ڴ濨���ش����־��Ϣ�洢��ַ
#define START_ADDRESS   0x0000
#define OFFSET_1        0x3000//��ȡ�����ڴ濨ƫ�Ƶ�ַ
#define OFFSET_2        0x4000//д�뷴���ڴ濨ƫ�Ƶ�ַ
/**************************************************/
/**************************************************/
/****************RFM2gͷ�ļ����궨�����*********/
/**************************************************/
/**************************************************/
enum MainControlMode//���ش����־��Ϣ
{
	RF_Query_MissData = 1,//�����ڴ濨��ѯģʽ���䵯������
	RF_Break_MissData,//�����ڴ濨�ж�ģʽ���䵯������
	UDP,//���ݿ��õ�
	SYS_Init,//�����ڴ濨����ϵͳ��ʼ��
	Reboot,//����VxWorksϵͳ
	PRF_Start,
	PRF_Stop,
	Last
};
enum  MainControlMode static MainCtrolMode = RF_Break_MissData;

#define TIMEOUT         60000   //��λΪms

int RFM_Card_Operate::RFM_Card_Init(rfm2gEventType EventType)//�����ڴ濨��ʼ����������ʼ��Handle����Ȳ���
{
	RFM2G_STATUS result;
	/* Open the Reflective Memory device */
	sprintf(device, "%s%d", DEVICE_PREFIX, numDevice);
	result = RFM2gOpen(device, &Handle);
	if (result != RFM2G_SUCCESS)
	{
		printf("ERROR: RFM2gOpen() failed.\n");
		printf("Error: %s.\n\n", RFM2gErrorMsg(result));
		return(-1);
	}
	/*��ȡ�����ڴ濨���ͺ��Լ��ڴ��С��Ϣ*/
	result = RFM2gGetConfig(Handle, &config);
	if (result == RFM2G_SUCCESS)
	{
		printf("\nNode ID is %d\n", config.NodeId);
		printf("The total memory size of %s is %d MBytes\n", config.Device, config.MemorySize / 1048576);
		printf("The memory offset range is 0x00000000~0x10000000\n");
	}
	else
	{
		printf("ERROR: RFM2gGetConfig() failed.\n");
		printf("Error: %s.\n\n", RFM2gErrorMsg(result));
		return(-1);
	}
	/*���ô�С�ˣ�ʹ�����ֽڷ�ת*/
	result_ByteSwap = RFM2gSetPIOByteSwap(Handle, RFM2G_FALSE);
	if (result_ByteSwap != RFM2G_SUCCESS)/*���ô�С��ʧ��*/
	{
		printf("ERROR: RFM2gSetPIOByteSwap() failed.\n");
		printf("Error: %s.\n\n", RFM2gErrorMsg(result_ByteSwap));
		return(-1);
	}
	result_ByteSwap = RFM2gGetPIOByteSwap(Handle, &byteSwap);
	if (result_ByteSwap != RFM2G_SUCCESS)/*��ȡ��С������״̬ʧ��*/
	{
		printf("ERROR: RFM2gGetPIOByteSwap() failed.\n");
		printf("Error: %s.\n\n", RFM2gErrorMsg(result_ByteSwap));
		return(-1);
	}
	else/*��ȡ��С������״̬�ɹ�*/
	{
		if (byteSwap == RFM2G_TRUE)
		{
			printf("The byte swapping of PIO transfers to an RFM2g device is enabled!\n");
		}
		else
		{
			printf("The byte swapping of PIO transfers to an RFM2g device is Disabled!\n");
		}
	}
	//д����ģʽ��־λ
	int temp = (int)MainCtrolMode;
	result = RFM2gWrite(Handle, RFCARD_TRANS_MODE_ADDR, (void *)&temp, sizeof(int));//����ַRFCARD_TRANS_MODE_ADDRд�뵱ǰ�����ڴ濨����ģʽ����
	if (result != RFM2G_SUCCESS)
	{
		printf("Error: %s\n", RFM2gErrorMsg(result));
		RFM2gClose(&Handle);
		return(-1);
	}
	RFM_Card_EnableEvent(EventType);//ʹ��RFM2GEVENT_INTR2�ж�

}
RFM2G_STATUS RFM_Card_Operate::RFM_Card_EnableEvent(rfm2gEventType EventType)
{
	/* Now wait on an interrupt from the other Reflective Memory board */
	EventInfo_Receive.Event = EventType;  /* We'll wait on this interrupt */
	EventInfo_Receive.Timeout = TIMEOUT;       /* We'll wait this many milliseconds */
	RFM2G_STATUS result = RFM2gEnableEvent(Handle, EventType);//ʹ�ܽ��յ��ж�����RFM2GEVENT_INTR2
	if (result != RFM2G_SUCCESS)
	{
		printf("Error: %s\n", RFM2gErrorMsg(result));
		RFM2gClose(&Handle);
		return(result);
	}
}
RFM2G_STATUS RFM_Card_Operate::RFM_Card_DisableEvent()
{
	//�ر��ж�
	RFM2G_STATUS result = RFM2gDisableEvent(Handle, EventInfo_Receive.Event);
	return result;

}


RFM2G_STATUS RFM_Card_Operate::RFM_Write_Missle(struct MissilePosInfo outbuffer, rfm2gEventType EventType)
{
	RFM2G_STATUS result = RFM2gWrite(Handle, OFFSET_WRT, (void *)&outbuffer, sizeof(struct  MissilePosInfo));
	/* Send an interrupt to the other Reflective Memory board */
	result = RFM2gSendEvent(Handle, OhterNodeID, EventType, 0);
	Sleep(2);//��ʱ������Ҫ����Ȼ��������µ�һ�ν��յ�����һ�ε����һ����������
	return result;
}

RFM2G_STATUS RFM_Card_Operate::WaitForEvent()
{
	RFM2G_STATUS result = RFM2gWaitForEvent(Handle, &EventInfo_Receive);
	/* Got the interrupt, see who sent it */
	OhterNodeID = EventInfo_Receive.NodeId;
	return result;
}

RFM2G_STATUS RFM_Card_Operate::RFM_Read_Missle(struct MissilePosInfo &inbuffer)
{
	RFM2G_STATUS result = RFM2gRead(Handle, OFFSET_RD, (void *)&inbuffer, sizeof(struct  MissilePosInfo));
	return result;
}

RFM_Card_Operate::~RFM_Card_Operate()//�����ڴ濨��ʼ����������ʼ��Handle����Ȳ���
{
	//Disable�ж�
	RFM_Card_DisableEvent();
	//�رշ����ڴ濨
	RFM2gClose(&Handle);
}


// �жϵ����ṹ�������Ƿ����
int RFM_Card_Operate::StructCMP(struct MissilePosInfo Para1, struct MissilePosInfo Para2)
{
#ifdef DEBUG_MissStruct80Bytes   //����80Bytes�ĵ����ṹ��
	if (Para1.CurrentTime == Para2.CurrentTime &&
		Para1.Position[0] == Para2.Position[0] &&
		Para1.Position[1] == Para2.Position[1] &&
		Para1.Position[2] == Para2.Position[2] &&
		Para1.Velocity[0] == Para2.Velocity[0] &&
		Para1.Velocity[1] == Para2.Velocity[1] &&
		Para1.Velocity[2] == Para2.Velocity[2] &&
		Para1.Acceleration[0] == Para2.Acceleration[0] &&
		Para1.Acceleration[1] == Para2.Acceleration[1] &&
		Para1.Acceleration[2] == Para2.Acceleration[2] &&
		Para1.theta == Para2.theta &&
		Para1.psi == Para2.psi &&
		Para1.gamma == Para2.gamma &&
		Para1.sOmegaX1 == Para2.sOmegaX1 &&
		Para1.sOmegaY1 == Para2.sOmegaY1 &&
		Para1.sOmegaZ1 == Para2.sOmegaZ1 &&
		Para1.sTheta == Para2.sTheta &&
		Para1.sAlpha == Para2.sAlpha &&
		Para1.sSigma == Para2.sSigma &&
		Para1.counter == Para2.counter
		)//�ṹ����ȷ���1
		return 1;
	else//�ṹ�岻��ȷ���0
		return 0;
#elif defined DEBUG_MissStruct520Bytes  //����520Bytes�ĵ����ṹ��
	if ((fabs(Para1.CurrentTime - Para2.CurrentTime) < 0.0000001) &&
		(fabs(Para1.Position[0] - Para2.Position[0]) < 0.0000001) &&
		(fabs(Para1.Position[1] - Para2.Position[1]) < 0.0000001) &&
		(fabs(Para1.Position[2] - Para2.Position[2]) < 0.0000001) &&
		(fabs(Para1.Velocity[0] - Para2.Velocity[0]) < 0.0000001) &&
		(fabs(Para1.Velocity[1] - Para2.Velocity[1]) < 0.0000001) &&
		(fabs(Para1.Velocity[2] - Para2.Velocity[2]) < 0.0000001) &&
		(fabs(Para1.Acceleration[0] - Para2.Acceleration[0]) < 0.0000001) &&
		(fabs(Para1.Acceleration[1] - Para2.Acceleration[1]) < 0.0000001) &&
		(fabs(Para1.Acceleration[2] - Para2.Acceleration[2]) < 0.0000001) &&
		(fabs(Para1.theta - Para2.theta) < 0.0000001) &&
		(fabs(Para1.psi - Para2.psi) < 0.0000001) &&
		(fabs(Para1.gamma - Para2.gamma) < 0.0000001) &&
		(fabs(Para1.sOmegaX1 - Para2.sOmegaX1) < 0.0000001) &&
		(fabs(Para1.sOmegaY1 - Para2.sOmegaY1) < 0.0000001) &&
		(fabs(Para1.sOmegaZ1 - Para2.sOmegaZ1) < 0.0000001) &&
		(fabs(Para1.sTheta - Para2.sTheta) < 0.0000001) &&
		(fabs(Para1.sAlpha - Para2.sAlpha) < 0.0000001) &&
		(fabs(Para1.sSigma - Para2.sSigma) < 0.0000001) &&
		(fabs(Para1.uiWaveWid - Para2.uiWaveWid) < 0.0000001) &&
		(fabs(Para1.uiApcHight - Para2.uiApcHight) < 0.0000001) &&
		(memcmp(Para1.Rsvd, Para2.Rsvd, sizeof(short) * (256 - 42)) == 0) &&//�Ƚ�int�����Ƿ����
		(Para1.usDataFlag == Para2.usDataFlag) &&
		(Para1.usDataValid == Para2.usDataValid) &&
		(Para1.counter == Para2.counter) &&
		(Para1.usSumCheck == Para2.usSumCheck)
		)//�ṹ����ȷ���1
		return 1;
	else//�ṹ�岻��ȷ���0
		return 0;
#endif
}

