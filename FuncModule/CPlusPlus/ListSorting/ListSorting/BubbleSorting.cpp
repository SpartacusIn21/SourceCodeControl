/*
FileName: BubbleSorting.h
Create Time:   2015/09/04
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference:  ������Ա���Ա��䡷����13.2.9 ��ν��е���������
Description: ��1���������ð�������㷨��
*/
#include<stdio.h>
#include<stdlib.h>
#include"BubbleSorting.h"
linklist *head = NULL;//�����д���ŵ�.h�ļ��оͻ���벻ͨ����why?
linklist* CreateList(int*arr, int len)//�����鴴���������׽��δ������
{
	int data;
	linklist *pCurrent, *rear;
	head = (linklist*)malloc(sizeof(linklist));
	rear = head;

	int count = 0;
	while(count<len)
	{
		pCurrent = (linklist*)malloc(sizeof(linklist));
		pCurrent -> data = arr[count];
		rear -> next = pCurrent;
		rear = pCurrent;
		count++;
	}
	rear -> next = NULL;
	return head;
}

void ShowList(linklist *p)//��ӡ������
{
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

}

void BubbleSortList(linklist *p)//����ð������
{
	linklist *_temp = p ->next;
	linklist *_node = p ->next;
	int temp;
	for(;_temp->next;_temp = _temp -> next)//�����������������,n-1��
	{
		for(_node = p->next; _node->next; _node = _node ->next)//����ʵ������ƽ����ð�������㷨д����ֻ�������������Ե�ʣ���̫����д��ѭ������Ϊn + n-1 + ... + 1 = n*(n+1)/2��(��Ӧ�Ƚϴ���Ϊn-1+n-2+...+1 = n*(n-1)/2)������ѭ������Ϊn*n,�Ƚϴ���Ϊ(n-1)*n
		{
			if(_node->data > _node ->next->data)//�ı��С�ž��ܸı�������������˳��
			{
				temp = _node->data;
				_node->data =_node->next->data;
				_node->next->data = temp;
			}
		
		}
	}

}