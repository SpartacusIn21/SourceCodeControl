/**
 * ����ELF hash�㷨
 * 
 *
 * */
#include <iostream>
#include <string>
using namespace std;
unsigned int ELFHash(char *key)  
{  
    unsigned int hash = 0;  
    unsigned int g = 0;  
  
    while (*key)  
    {  
        hash = (hash << 4) + (*key++);//hash����4λ���ѵ�ǰ�ַ�ASCII����hash����λ��   
        g=hash&0xf0000000L;  
        if (g)  
        {  
            //�����ߵ���λ��Ϊ0����˵���ַ�����7�����������ڴ��7���ַ�������������ټ���һ���ַ�ʱ����һ���ַ��ᱻ�Ƴ������Ҫ�����´���  
            //�ô���������λΪ0���ͻ����Ӱ��5-8λ�������Ӱ��5-31λ����ΪC����ʹ�õ�������λ  
            //��Ϊ1-4λ�ոմ洢���¼��뵽�ַ������Բ���>>28  
              
            hash ^= (g>> 24);  
              
            //�������д��벢�����X��Ӱ�죬����X��hash�ĸ�4λ��ͬ���������д���&~����28-31(��4λ)λ���㡣  
              
            hash &= ~g;  
        }  
    }  
    //����һ������λΪ0���������������λ�����⺯�������Ӱ�졣(���ǿ��Կ��ǣ����ֻ���ַ�������λ������Ϊ��)  
    return hash;  
}  
int main(){
	string a="abc",b="12rfs";
	cout << "hash(" << a << ")" << ELFHash((char*)a.c_str()) << endl << "hash(" << b << ")" << ELFHash((char*)b.c_str()) << endl;
	return 0;
}
