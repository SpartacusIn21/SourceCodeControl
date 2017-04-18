/*
FileName: Course_CPlusPlus_Week2.cpp
Create Time:   2015/10/09
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference: https://www.coursera.org/learn/cpp-chengxu-sheji/programming/CpvBs/bian-cheng-zuo-ye-c-chu-tan 
Description: ��1���򵥵�ѧ����Ϣ�������(2)�����ȷ��ʹ��geline������ȡ��ĳ���ָ����ֿ��Ĳ�ͬ���͵�һ������;
*/
/*
�򵥵�ѧ����Ϣ�������ʵ��

��Դ: POJ (Coursera��������POJ����ɵ�ϰ�⽫�������Coursera�����ɼ���)

ע�⣺ ��ʱ������: 1000ms �ڴ�����: 65536kB

����

��һ��ѧ����Ϣ��������У�Ҫ��ʵ��һ������ѧ�����࣬�������г�Ա������Ӧ����˽�еġ�

��ע������ϵͳ�޷��Զ��жϱ����Ƿ�˽�С����ǻ��ڽ���֮��ͳһ����ҵ���м�飬��ͬѧ���ϸ�����ĿҪ����ɣ�������ܻ�Ӱ����ҵ�ɼ�����

����

���������䣬ѧ�ţ���һѧ��ƽ���ɼ����ڶ�ѧ��ƽ���ɼ�������ѧ��ƽ���ɼ�������ѧ��ƽ���ɼ���

����������ѧ��Ϊ�ַ����������ո�Ͷ��ţ�����Ϊ���������ɼ�Ϊ�Ǹ�������

����������֮����õ���Ӣ�Ķ���","�������޶���ո�

���

һ�У���˳����������������䣬ѧ�ţ�����ƽ���ɼ�������ȡ������

����������֮����õ���Ӣ�Ķ���","�������޶���ո�

��������

Tom,18,7817,80,80,90,70
�������

Tom,18,7817,80
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class student
{
private:
	char Name[20];
	char StudentID[20];
	unsigned int Age;
	unsigned int Score[4];
public:
	student(const char *name, const char *studentid, unsigned int age, unsigned int *score) :Age(age)
	{
		strcpy_s(Name, name);
		strcpy_s(StudentID, studentid);
		memcpy(Score, score, 4 * sizeof(unsigned int));
	}
	void Print()
	{
		cout << Name << "," << Age << "," << StudentID << "," << (int)((Score[0] + Score[1] + Score[2] + Score[3]) / 4) << endl;
	}
};
int main()
{
	char Name[20];
	char StudentID[20];
	unsigned int Age;
	unsigned int Score[4];
	string str;
	getline(cin, str, ',');//�����getlineʹ��һ��ѭ����ȡstr�����˸�ֵ��һ��string����Ҳ�ǿ��Եģ������������������Ƚϴ�������
	strcpy_s(Name, str.c_str());//����ʹ��Name(NameΪָ�����) = str.c_str();��Ϊ������ָ�븳ֵ���´�str��ֵ�ı���Ӱ���Ѿ���ֵ���ı���
	getline(cin, str, ',');
	Age = atoi(str.c_str());
	getline(cin, str, ',');
	strcpy_s(StudentID, str.c_str());
	getline(cin, str, ',');
	Score[0] = atoi(str.c_str());
	getline(cin, str, ',');
	Score[1] = atoi(str.c_str());
	getline(cin, str, ',');
	Score[2] = atoi(str.c_str());
	getline(cin, str);//��Ϊ���һ��û�еķָ����ǻس�������������ʹ��Ĭ�ϵļ���
	Score[3] = atoi(str.c_str());
	student Tim(Name, StudentID, Age, Score);
	Tim.Print();
	return 0;
}