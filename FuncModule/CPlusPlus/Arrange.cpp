/*
FileName: Arrange.cpp
Create Time:   2015/09/05
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference: 
Description: ��1������û����ֵͬ��������λ�õ��������ࣻ
*/
/* 
  ͨ������ϣ�����n����ͬԪ�ص��������з�ʽ��ȷ��һ����ѵ����򡣱���a,b,c�����з�ʽ��abc,acb,bac,bca,cab,cba���֡�
  ���ڲ��÷ǵݹ��c++������������з�ʽ�����ѣ����Բ��õݹ���һ�ֱȽϲ���ķ�����
  ������ǣ���ÿ��Ԫ�طŵ�n��Ԫ����ɵĶ�����ǰ����Ȼ���ʣ��Ԫ�ؽ���ȫ���У����εݹ���ȥ��
  ���磺
  a b c
  ���Ƚ�a�ŵ���ǰ��������һ��Ԫ�ؽ�������Ȼ������b c��Ȼ��a�Żر���λ�� 
   ��� a b c�� a c b
  ��ν�b�ŵ���ǰ��������һ��Ԫ�ؽ�������Ȼ������a c��Ȼ��b�Ż�
   ��� b a c�� b c a
   ������
  �����4��Ԫ�أ��ͽ�Ԫ�����ηŵ���һ��Ԫ�ص�λ�ã��������������ǰ���3Ԫ������
*/
int COUNT = 0;//�ڵ���perm�����ĵط���Ҫ��COUNT��ʼ��Ϊ��
void SWAP(int *a,int *b) //��������
{
 int temp;
 temp = *a;
 *a = *b;
 *b = temp;
}
bool check(int *list, int n){//�ų������д���ֵ��ͬ����������λ�õ����
	 for(int i =0; i < n-1 ; i++){
		if(abs(list[i] - list[i+1]) % 13 == 0){
			return false;
		}
	 }
	 return true;
}
int perm(int *list, int i, int n)//�ݹ�ʵ��ȫ����
{
	 int j/*����,temp*/;
	 if(i == n /*&& check(list, n)*/)//����û�����ڵ���ֵ��ͬ�Ĳ�����
	 {
		for(j = 0; j < n; j++)
		{
		cout<<list[j];
		cout<<" ";
		}
		COUNT++;
		cout<<endl; //��
	 }
	 else
	 {
		  for(j = i; j < n; j++)
		  {
			   SWAP(list+i,list+j); //SWAP(list+i,list+j,temp);
			   perm(list,i+1,n);
			   SWAP(list+i,list+j); //SWAP(list+i,list+j,temp);
		  }
	 }
	 return COUNT;
}