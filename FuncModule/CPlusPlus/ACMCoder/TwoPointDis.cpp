/*
FileName: BinaryTree.cpp
Create Time:   2015/09/26
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference:  http://acm.acmcoder.com/showproblem.php?pid=2001 
Description:
*/

/*
Problem Description
�����������꣨X1,Y1��,��X2,Y2��,���㲢��������ľ��롣
Input
���������ж��飬ÿ��ռһ�У���4��ʵ����ɣ��ֱ��ʾx1,y1,x2,y2,����֮���ÿո������
Output
����ÿ���������ݣ����һ�У����������λС����
Sample Input
0 0 0 1
0 1 1 0
Sample Output
1.00
1.41
*/
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int TwoPointDis()
{
	double x1,y1,x2,y2;
	double Result[1000] = {0};
	int count = 0;
	while(cin>>x1>>y1>>x2>>y2)
	{
		Result[count++] = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	}
	for(int i = 0; i < count; i++)
		cout<< fixed << setprecision(2) << Result[i] << endl;

	return 0;
}