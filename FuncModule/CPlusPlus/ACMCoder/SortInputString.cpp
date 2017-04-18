/*
FileName: BinaryTree.cpp
Create Time:   2015/09/26
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference:  http://acm.acmcoder.com/showproblem.php?pid=2000
Description:
*/

/*
Problem Description
���������ַ��󣬰����ַ���ASCII���С�����˳������������ַ���
Input
���������ж��飬ÿ��ռһ�У��������ַ���ɣ�֮���޿ո�
Output
����ÿ���������ݣ����һ�У��ַ��м���һ���ո�ֿ���
Sample Input
qwe
asd
zxc
Sample Output
e q w
a d s
c x z
*/
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int SortInputString()
{
	char Str[1000][3] = {0};
	int count = 0;
	while(cin>>Str[count])
	{
		for(int i = 0; i < 3; i++)
			for(int j = 1; j < 3-i; j++) 
			{
				if(Str[count][j] < Str[count][j-1])
				{
					Str[count][j] = Str[count][j] ^ Str[count][j-1];
					Str[count][j-1] = Str[count][j] ^ Str[count][j-1];
					Str[count][j] = Str[count][j] ^ Str[count][j-1];
				}
			}
		count++;
	}
	for(int i = 0; i < count; i++)
	{
		cout << Str[i][0] << " " << Str[i][1] << " " << Str[i][2] << endl;
	}
	return 0;
}