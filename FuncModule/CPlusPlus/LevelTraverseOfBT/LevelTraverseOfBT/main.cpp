//Ref: �����֮���������ֲ����������
//Author: Chen Yangchun
//Data: 2015/8/30
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*ʹ�ò�α����������ö�����
	                                   | 1 |
									  -    -
									-       -
								  | 2 |    | 3 |  
								  -  -         -
								-     -         -
							 | 4 |   | 5 |      | 6 |
*/
struct Node
{
	int data;
	Node* lChild;
	Node* rChild;
};
//��α������ݹ���룬���б�������Ҫ�Ӹ���㿪ʼ��Ч�ʱȽϵ�
int PrintNodeAtLevel(Node *root, int level)
{
	if(!root || level < 0)
	{
		return 0;
	}
	else if(level == 0 )
	{
		cout << root->data << " ";
		return 1;
	}
	return PrintNodeAtLevel(root -> lChild, level - 1) + PrintNodeAtLevel(root -> rChild, level - 1);//�ֲ��������α����Ĺؼ���@�������������������
	//return PrintNodeAtLevel(root -> rChild, level - 1) + PrintNodeAtLevel(root -> lChild, level - 1);//�ֲ��������α����Ĺؼ���@�������������������
}
//����α���������
//root:���������ڵ�
//����Ҫ�Ӹ��ڵ��ظ�������Ч�ʱȽϸ�
void PrintNodeByLevel(Node* root)
{
	if(root == NULL)
		return ;
	vector<Node*> vec;
	vec.push_back(root);
	int cur = 0;
	int last = 1;
	while(cur < vec.size())//����BT��Level��ѭ��
	{
		last = vec.size();
		while(cur < last)//��ǰLevel��ĸ����ڵ�ѭ��
		{
			cout << vec[cur]->data << " ";
			if(vec[cur]->lChild)
				vec.push_back(vec[cur]->lChild);
			if(vec[cur]->rChild)
				vec.push_back(vec[cur]->rChild);
			cur++;

		}
		cout << endl;
	}


}
void PrintByReverseLevel(Node *root)//�������Ϸ��ʶ�������������
{
	vector<Node *> q;
	stack<int> q2; //��¼��ǰ�ڵ�Ĳ��
	Node *p;
	q.push_back(root);
	q2.push(0);
	int cur=0;
	int last=1;
	while(cur<q.size())
	{
		int level=q2.top();
		last=q.size();
		while(cur<last)
		{
			p=q[cur];
			if(p->rChild)
			{
				q.push_back(p->rChild);
				q2.push(level+1);
			}
			if(p->lChild)
			{
				q.push_back(p->lChild);
				q2.push(level+1);
			}
			cur++;
		}
	}
	while(!q2.empty())
	{
		cout << q[--cur]->data;
		int temp=q2.top();
		q2.pop();
		if(q2.empty() || temp!=q2.top())
			cout << endl;
	}
}
int main()
{
	//Init BT(Binary Tree)
	Node node1,node2,node3,node4,node5,node6;
	node4.data=4;
	node4.lChild=NULL;
	node4.rChild=NULL;
	node5.data=5;
	node5.lChild=NULL;
	node5.rChild=NULL;
	node2.data=2;
	node2.lChild=&node4;
	node2.rChild=&node5;
	node6.data=6;
	node6.lChild=NULL;
	node6.rChild=NULL;
	node3.data=3;
	node3.lChild=NULL;
	node3.rChild=&node6;
	node1.data=1;
	node1.lChild=&node2;
	node1.rChild=&node3;
	cout << "*******����1********" <<endl;
	////��α������в㣬@֪���������
	//for(int i = 0; i < 3; i++)
	//{
	//	int Num = PrintNodeAtLevel(&node1,i);
	//	cout << "Num:" << Num <<endl;
	//}
	//��α������в㣬@��֪���������
	for(int i = 0; ; i++)
	{
		if(!PrintNodeAtLevel(&node1,i))//Ч�ʽϵͣ���Ϊÿ�㶼��Ҫ�Ӹ��ڵ㿪ʼ����
			break;
		cout << endl;
	}
	cout << "*******����2********" <<endl;
	PrintNodeByLevel(&node1);//Ч�ʱȽϸߣ������˶��и��ÿ�����ʱֻ��Ҫ��һ�����Ϣ����
	cout << "*******����1����������********" <<endl;
	PrintByReverseLevel(&node1);//Ч�ʱȽϸߣ������˶��и��ÿ�����ʱֻ��Ҫ��һ�����Ϣ����
	getchar();
	return 0;
}