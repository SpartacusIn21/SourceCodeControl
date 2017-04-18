#include<stdio.h>
#include<string.h>

void CombineRecursiveImpl(const char* str, char* begin, char* end)//����úú��о��£�ָ�����õıȽ�����
{
	if(*str == 0)//����strΪ��ʱ
	{
		*end = 0;
		if(begin != end)//����Ϊ��ʱ����ַ�
			printf("%s ", begin);
		return;
	}
	CombineRecursiveImpl(str+1, begin, end);
	*end = *str;
	CombineRecursiveImpl(str+1, begin, end+1);
}

void CombineRecursive(const char str[])
{
	if(str == NULL)
		return;
	const int MAXLENGTH = 64;
	char result[MAXLENGTH];
	CombineRecursiveImpl(str, result, result);
}

int main()
{
	CombineRecursive("abc");
	printf("\n");
	return 0;	
}