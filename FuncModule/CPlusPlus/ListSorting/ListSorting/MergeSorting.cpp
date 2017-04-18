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
#include<iostream>
#include"MergeSorting.h"
using namespace std;
void Merge(SqList SR, SqList &TR, int i, int m, int n)
{
	int j,k;
	for(j = m+1,k=i; i<=m&&j<=n; ++k)
	{
		if(SR.r[i] <= TR.r[j])
		{
			TR.r[k] = SR.r[i++];
		}
		else
		{
			TR.r[k] = SR.r[j++];
		}
		
	}
	while(i <= m)
			TR.r[k++] = SR.r[i++];
	while(j <=n)
		TR.r[k++] = SR.r[j++];
}

void MSort(SqList SR, SqList &TR1, int s, int t)
{
	int m;
	SqList TR2;
	if(s == t)//��������������SqList��Ϊ�˰�����һ��������������洢����
		TR1.r[s] = SR.r[t];
	else
	{
		m = (s+t)/2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m+1, t);
		Merge(TR2, TR1, s, m, t);
	}

}
void MergeSort(SqList &L)
{
	MSort(L, L ,1, L.length);
}