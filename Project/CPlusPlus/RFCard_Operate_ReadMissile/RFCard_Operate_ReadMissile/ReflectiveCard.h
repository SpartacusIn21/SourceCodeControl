#pragma once
#if (defined(WIN32))
#include "rfm2g_windows.h"
#endif
#include "rfm2g_api.h"
#include <iostream>
using namespace std;
void RFM_Break();
//#define DEBUG_MissStruct80Bytes    //�����ṹ��Ϊ80Bytes
#define DEBUG_MissStruct520Bytes    //�����ṹ��Ϊ520Bytes
#ifdef DEBUG_MissStruct80Bytes  //�����ṹ��Ϊ80Bytes
struct  MissilePosInfo//��������λ����Ϣ�ṹ�壬ռ��80Bytes�����޸�Ϊռ��520Bytes�Ľṹ���ʽ
{
	float CurrentTime;//����λ�ö�Ӧ��λ��ʱ��
	float Position[3];//��������λ��
	float Velocity[3];//�����ڸõ���λ�ô������ٶȷ���
	float Acceleration[3];//�����ڸõ���λ�ô��������ٶȷ���
	float theta;
	float psi;
	float gamma;
	float sOmegaX1;
	float sOmegaY1;
	float sOmegaZ1;
	float sTheta;
	float sSigma;
	float sAlpha;
	int counter;//��ǰ����ʱ�̵ķ�λ����
};
#elif defined DEBUG_MissStruct520Bytes   //�����ṹ��Ϊ520Bytes
struct  MissilePosInfo//��������λ����Ϣ�ṹ�壬ռ��80Bytes�����޸�Ϊռ��520Bytes�Ľṹ���ʽ
{
	float CurrentTime;//����λ�ö�Ӧ��λ��ʱ��
	float Position[3];//��������λ��
	float Velocity[3];//�����ڸõ���λ�ô������ٶȷ���
	float Acceleration[3];//�����ڸõ���λ�ô��������ٶȷ���
	float theta;
	float psi;
	float gamma;
	float sOmegaX1;
	float sOmegaY1;
	float sOmegaZ1;
	float sTheta;
	float sSigma;
	float sAlpha;
	float  uiWaveWid;              // ����
	float  uiApcHight;             // Ԥ������߶�,shortռ�������ֽڣ�intռ��4���ֽ�
	short  Rsvd[214];           // ������
	short   usDataFlag;             // ������־��
	short   usDataValid;            // ������Ч��־
	short   counter;					//��ǰ����ʱ�̵ķ�λ����// �������¼��� 
	short   usSumCheck;             // ����У��
};
#else 
printf("Debug Macro is wrong!\n");
#endif
class RFM_Card_Operate{
private:
	RFM2G_BOOL 	   byteSwap;			/*��ȡ��С������״̬��ΪRFM2G_TRUE��RFM2G_FALSE*/
	STDRFM2GCALL   result_ByteSwap;     /*��С�����÷���ֵ*/
	RFM2GEVENTINFO EventInfo_Receive;              /* Info about received interrupts    */
	UINT OFFSET_WRT = 0x4000;//�����ڴ濨д��ַ����Ĭ��Ϊ0x3000
	UINT OFFSET_RD = 0x3000;//�����ڴ濨����ַ����Ĭ��Ϊ0x4000
	

protected:

public:
	//�����ڴ濨���ò�������
	RFM2G_INT32 numDevice;
	RFM2G_NODE     OhterNodeID;             /* OhterNodeID*/
	char     device[40];             /* Name of PCI RFM2G device to use   */
	RFM2GHANDLE    Handle = 0;//�����ڴ濨������ǳ���Ҫ
	RFM2GCONFIG    config;					/*��ȡRFM2g���ýṹ*/
	
	//�����ڴ濨���ú���
	RFM_Card_Operate(RFM2G_INT32 numDevice_Para, RFM2G_NODE OhterNodeID_Para) :numDevice(numDevice_Para), OhterNodeID(OhterNodeID_Para){};
	int RFM_Card_Init(rfm2gEventType EventType);//�����ڴ濨��ʼ��
	RFM2G_STATUS RFM_Card_EnableEvent(rfm2gEventType EventType);//Enable�ж�
	RFM2G_STATUS RFM_Card_DisableEvent();//Disable�ж�
	RFM2G_STATUS WaitForEvent();
	RFM2G_STATUS RFM_Write_Missle(struct MissilePosInfo outbuffer,rfm2gEventType EventType);
	RFM2G_STATUS RFM_Read_Missle(struct MissilePosInfo &inbuffer);
	int StructCMP(struct MissilePosInfo Para1, struct MissilePosInfo Para2);//�ԱȽṹ���С
	~RFM_Card_Operate();


};

