/*
FileName: MovingWay
Create Time:   2015/09/16
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference: 
Description: ��1����Ϊ�����⣬����������һ��n*n�ľ���char�ַ�������'B'��ʾ��㣬'H'��ʾ�յ㣬'-'��ʾ��·��ͨ,'#'��ʾ��·��ͨ����������ľ����ַ��жϴ�'B'��'H'�Ƿ����·��;
			 ��2������֮��·���Ƿ����;
*/

/*
ʾ��:
1.�������� B###
		   #---
		   ---#
		   H---
���B��H֮�䲻ͨ�����'N'

2.�������� B-
		   -H
���B��H֮��ͨ�����'Y'
*/
#include<iostream>
#include<map>
using namespace std;
int R=0, C=0;
int endx,endy;
bool HaveRoad(char Map_Temp[400][400], int startx,int starty)//��Map_Temp��Ӧλ��д'r'��ʾ�Ѿ���ȡ����λ��
{
	if(startx < 0 || startx >= R || starty < 0 || starty >= C)//����������ʱ����false
	{
		return false;
	}
	else if( startx == endx && starty == endy)//��ʾ�ҵ���Ӧ��·��������true
	{
		return true;
	}
	else if((Map_Temp[startx+1][starty] == '-' || Map_Temp[startx+1][starty] == 'H') && Map_Temp[startx+1][starty] != 'r')//��һ��Ϊ'-'����'H'��ʾ��·���ߣ����ǲ��ܵ���'r'������'r'��ʾ��·���Ѿ��߹��ˣ����߾ͻ���ѭ��
	{
		Map_Temp[startx+1][starty] = 'r';
		return HaveRoad(Map_Temp, startx+1, starty);
	}	
	else if((Map_Temp[startx][starty+1] == '-' || Map_Temp[startx][starty+1] == 'H') && Map_Temp[startx][starty+1] != 'r')
	{
		Map_Temp[startx][starty+1] = 'r';
		return HaveRoad(Map_Temp, startx, starty+1);
	}
	else if((Map_Temp[startx-1][starty] == '-' || Map_Temp[startx-1][starty] == 'H') && Map_Temp[startx-1][starty] != 'r')
	{
		Map_Temp[startx-1][starty] = 'r';
		return HaveRoad(Map_Temp, startx-1, starty);
	}
	else if((Map_Temp[startx][starty-1] == '-' || Map_Temp[startx][starty-1] == 'H') && Map_Temp[startx][starty-1] != 'r')
	{
		Map_Temp[startx][starty-1] = 'r';
		return HaveRoad(Map_Temp, startx, starty-1);
	}
	else
	{
		return false;
	}
}
int main()
{ 	
	
	int i,j;
	char Map_Temp[400][400] = {0};
	int startx,starty;
	cin >> R;
	cin >> C;
	for(i = 0; i < R; i++)
	{
		cin >> Map_Temp[i];
	}
	//find B and H
	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++)
		{
		
			if(Map_Temp[i][j] == 'B')
			{
				startx = i;
				starty = j;
			}
			else if(Map_Temp[i][j] == 'H')
			{
				endx = i;
				endy = j;	
			}
		}
	bool result = HaveRoad(Map_Temp, startx, starty);
	if(result)
		cout << "Y" << endl;
	else
		cout << "N" << endl;
	return 0;
}