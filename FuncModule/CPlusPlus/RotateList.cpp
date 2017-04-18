/*
FileName: RotateList.cpp
Create Time:   2015/09/04
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference:  https://leetcode.com/problems/rotate-list/
Description: ��1��List��תĩβK���ڵ㵽�׶ˣ�
*/
/*
���̣�
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //���ﶨ������ָ�뼴�ɣ�pָ��ָ��ǰk��Node��ͷ��qָ��ǰk��Node��β��Ȼ��headָ��q->next,Ȼ��lָ��list�����ڶ���ָ�룬��������p->next=p,q->next=NULL���ɡ�
        if(head == NULL || k == 0)//���Ϊ�ջ���K=0ֱ�ӷ���head����
            return head;
		//ͳ��List�ڵ���
        int NodeNums = 1;
        ListNode* tempNode = head;
		while((tempNode = tempNode->next) != NULL)
        {
            NodeNums++;
        }
		//����ضϵĽڵ�λ�ã������Ҫ�ú�����˼·
        int count = NodeNums - k - 1;//��ʽ1
        if((count < 0) && (k % NodeNums == 0))//��count<0��k������List�ڵ���ʱ��˵������Ҫ�����ı�
        {
            return head;
        }
        else if((count < 0) && (k % NodeNums != 0))//��count<0��k��������List�ڵ���ʱ����Ҫ����ͳ�ƽض�λ��
        {
            count = NodeNums - k % NodeNums-1;//��ʽ2������ʵ����ʽ1��һ����
        }
		//�����K���ڵ��ᵽListǰ����
        ListNode* p=head,*q=head,*l=head;
        while(count>0)
        {
            q = q->next;
            count--;
        }
        l = head = q->next;
        while(l->next != NULL)
        {
            l = l ->next;
        }
        l -> next = p;
        q -> next = NULL;
        return head;
        
    }
};