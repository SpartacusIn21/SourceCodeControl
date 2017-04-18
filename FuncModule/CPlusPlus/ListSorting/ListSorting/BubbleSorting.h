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

#ifndef _BUBBLESORTING_H_
#define _BUBBLESORTING_H_
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}linklist;
linklist* CreateList(int *arr, int len);
void ShowList(linklist *p);
void BubbleSortList(linklist *p);
#endif