// VisualSimulation_RFcardMissleRecv.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "ReflectiveCard.h"
using namespace System;
int main(array<System::String ^> ^args)
{
/*********************�����ڴ濨����������ʹ��ʾ��*********************/
	//�����ڴ濨��д���ݱ���
	RFM_Card_Operate RFCardMissOperate(1, 4);//����1ΪDevice ID���������ط����ڴ濨���豸ID��4Ϊ���շ�Node ID
	int result_RFM_CardInit = RFCardMissOperate.RFM_Card_Init(RFM2GEVENT_INTR1);//RFM2GEVENT_INTR1�Ǳ��ط����ڴ濨�����ж�����
	if (result_RFM_CardInit == -1)
	{
		printf("�����ڴ濨��ʼ������\n");
		return -1;
	}
	struct MissilePosInfo inbuffer;
	memset(&inbuffer, 0, sizeof(struct MissilePosInfo));

	//ѭ����ʼ
	//���ɵ������ݲ���ֵ��outbuffer
	//...
	//д�����ڴ濨
	//����������д�뷴���ڴ濨
	RFM2G_STATUS result_Event = RFCardMissOperate.WaitForEvent();
	if (result_Event != RFM2G_SUCCESS)
	{
		return(-1);
	}
	else
	{
		RFM2G_STATUS result_Read = RFCardMissOperate.RFM_Read_Missle(inbuffer);
		if (result_Read != RFM2G_SUCCESS)
		{
			return(-1);
		}
		else
		{
			RFM2G_STATUS result_Write = RFCardMissOperate.RFM_Write_Missle(inbuffer, RFM2GEVENT_INTR2);//RFM2GEVENT_INTR2��Զ�˷����ڴ濨�����ж�����
			if (result_Write != RFM2G_SUCCESS)
			{
				return(-1);
			}
		}
	}
	//...
	//ѭ������

/**************************************************************/
	
	return 0;
}
