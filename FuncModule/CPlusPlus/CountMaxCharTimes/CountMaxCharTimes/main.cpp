/*
FileName: CountMaxCharTimes
Create Time:   2015/09/18
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У����70����12044
Reference:  
Description: ��1��Ѱ��������ַ����г��ִ��������ַ��Լ����ֵĴ�����
*/
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

//����1��ʹ��map����
map<char,int> Map_char_int;
void CountTimesofChar(string Input)
{
	int len = Input.size();
	for(int i = 0; i < len; i++)//���ַ�������map����ӳ��
	{
		Map_char_int[Input[i]]++;
	}
	map<char,int>::iterator Max = Map_char_int.begin();//���ڴ洢���ִ�������iterator����
	(*Max).second = 0;
	for(map<char,int>::iterator item = Map_char_int.begin(); item != Map_char_int.end(); item++)//����Map��Ѱ�ҳ��ִ��������ַ�
	{
		if((*item).second > (*Max).second)//*itemȡ����keyֵ����(*item).secondȡ�Ĳ���valueֵ
		{
			Max = item;
		}
	}
	cout << (*Max).first << ":" << (*Max).second << endl;//����ַ����г��ִ��������ַ��Լ�����
}


//����2��ʹ����÷����������
void CountTimesofStr(string Input)
{
	int TimesofChar[26] = {0};//���ڴ洢�����ַ����ֵĴ���
	int len = Input.size();
	int index=0, MaxTimes=0;//����ͳ�Ƴ����������ַ�������TimesofChar�е�λ�ü�����
	for(int i = 0; i < len; i++)
	{
		TimesofChar[Input[i]-'a']++; 
	}
	for(int i = 0; i < 26; i++)
	{
		if(TimesofChar[i] > MaxTimes)
		{
			index = i;
			MaxTimes = TimesofChar[i];
		}
	}
	cout << char(index + 'a') << ":" << MaxTimes << endl;

}
int main()
{
	cout << "Input a string:" << endl;
	string Input;
	//����1
	//getline(cin, Input);
	//CountTimesofChar(Input);
	//����2
	getline(cin, Input);
	CountTimesofStr(Input);
	return 0;
}
