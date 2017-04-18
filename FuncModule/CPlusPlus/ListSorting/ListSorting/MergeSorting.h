/*
FileName: BubbleSorting.h
Create Time:   2015/09/04
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference:  ������Ա���Ա��䡷����13.2.9 ��ν��е���������
Description: ��1��������Ĺ鲢�����㷨��
*/

#ifndef _MERGESORTING_H_
#define _MERGESORTING_H_
#define MAXSIZE 1024
#define LENGTH 8
typedef struct
{
	int r[MAXSIZE + 1];
	int length;
}SqList;
void Merge(SqList SR, SqList &TR, int i, int m, int n);
void MSort(SqList SR, SqList &TR1, int s, int t);
void MergeSort(SqList &L);

#endif