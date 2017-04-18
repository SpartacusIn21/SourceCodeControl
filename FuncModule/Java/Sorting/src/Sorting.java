/*
* ���������㷨
*ð������bubble sort�� �� O(n^2��������ѧ
*��β������(Cocktail sort��˫���ð������) �� O(n^2��
*��������insertion sort���� O(n^2)������ѧ
*Ͱ����bucket sort���� O(n); ��Ҫ O(k) ����ռ䡪��������ѧϰ
*��������(counting sort) �� O(n+k); ��Ҫ O(n+k) ����ռ䡪��������ѧϰ
*�ϲ�����merge sort���� O(nlog n); ��Ҫ O(n) ����ռ䡪��������ѧϰ
*ԭ�غϲ����� O(n^2)
*�������������� ��Binary tree sort�� �� O(nlog n)����ʱ�䣻 O(n^2)�ʱ�䣻 ��Ҫ O(n) ����ռ�
*�볲����(Pigeonhole sort) �� O(n+k); ��Ҫ O(k) ����ռ�
*��������radix sort���� O(n��k); ��Ҫ O(n) ����ռ�
*Gnome ���� O(n^2)
*ͼ������� O(nlog n) with high probability����Ҫ ��1+��)n����ռ�
*/
/*
 * @Date: 4-24-2015
 * @author Yangchun, Chen
 * �����㷨
 * ��1��Selection_Sorting��ѡ������
 * ��2��Bubble_Sorting��ð������
 * ��3��Insert_Sorting����������
 */
public class Sorting {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		int [] intArray1 = {1, 23, 45, 32, 0, 100, 3, 5, 33};
		int [] intArray2 = {1, 23, 45, 32, 0, 100, 3, 5, 33};
		int [] intArray3 = {38, 65, 97, 76, 13, 27, 49};
		int [] intArray4 = {38, 65, 97, 76, 13, 27, 49};
		int [] intArray5 = {38, 65, 97, 76, 13, 27, 49};
		int [] intArray6 = {38, 65, 97, 76, 13, 27, 49};
		
		System.out.print("ѡ������:");	
		System.out.println();//�س�����
		Selection_Sorting(intArray1);
		System.out.println();//�س�����
		System.out.println();//�س�����
		
		System.out.print("ð������:");
		System.out.println();//�س�����
		Bubble_Sorting(intArray2);
		System.out.println();//�س�����
		System.out.println();//�س�����
		
		System.out.print("��������:");
		System.out.println();//�س�����
		Insert_Sorting(intArray3);
		System.out.println();//�س�����
		System.out.println();//�س�����
		
		System.out.print("��������:");//�ǳ���Ҫ����ΪЧ�ʸ߱�Ƶ��ʹ��	
		System.out.println();//�س�����
		System.out.print("����ǰ������Ԫ��");
		for(int a:intArray4){//��������
			System.out.print(a + " ");		
		}
		Quick_Sorting(intArray4, 0, intArray4.length-1);
		System.out.println();//�س�����
		System.out.print("����������Ԫ��");
		for(int a:intArray4){//��������
			System.out.print(a + " ");		
		}
		System.out.println();//�س�����
		System.out.println();//�س�����
		
		System.out.print("�鲢����:");//�ǳ���Ҫ�����ڶ๫˾Ƶ��ʹ��
		System.out.println();//�س�����
		System.out.print("����ǰ������Ԫ��");
		for(int a:intArray5){//��������
			System.out.print(a + " ");		
		}
		System.out.println();//�س�����
		Merge_Sorting(intArray5, 0, intArray5.length - 1);
		System.out.print("����������Ԫ��");
		for(int a:intArray5){//��������
			System.out.print(a + " ");	
		}
		System.out.println();//�س�����
		System.out.println();//�س�����
		
		System.out.print("ϣ������:");//�ǳ���Ҫ�����ڶ๫˾Ƶ��ʹ��
		System.out.println();//�س�����
		System.out.print("����ǰ������Ԫ��");
		for(int a:intArray6){//��������
			System.out.print(a + " ");		
		}
		System.out.println();//�س�����
		Shell_Sorting(intArray5, intArray5.length);
		System.out.print("����������Ԫ��");
		for(int a:intArray5){//��������
			System.out.print(a + " ");	
		}
		System.out.println();//�س�����
		System.out.println();//�س�����
	}
	public static void Selection_Sorting(int[] Array){//ѡ�����򷨣���Ϊͨ���ڶ��������ʱ��ÿ�ζ�ѡ����С�Ļ����������ݣ�	
		int keyvalue;
		int index;
		int temp;
		System.out.print("����ǰ������Ԫ��");
		for(int a:Array){//��������
			System.out.print(a + " ");		
		}
		System.out.println();//�س�����
		for(int i = 0; i < Array.length; i++){
			index = i;
			keyvalue = Array[i];
			for(int j = i; j < Array.length; j++){//����һ��ѡ����С������
				if(Array[j] < keyvalue){//�����keyvalueС���͸���index��keyvalue
					index = j;
					keyvalue = Array[j];
				}				
			}
			temp = Array[i];//������������Сֵ��iλ�õ�ֵ
			Array[i] = Array[index];
			Array[index] = temp;
		}		
		System.out.print("����������Ԫ��");
		for(int a:Array){//��������
			System.out.print(a + " ");		
		}
	}
	public static void Bubble_Sorting(int [] Array){//ð������
				
		System.out.print("����ǰ������Ԫ��");
		for(int a:Array){//��������
			System.out.print(a + " ");		
		}
		System.out.println();//�س�����
		for(int i = 0; i < Array.length; i++){		
			for(int j = 0; j < Array.length - i - 1; j++){
				if(Array[j] > Array[j+1]){
					Array[j] = Array[j] ^ Array[j+1];
					Array[j+1] = Array[j] ^ Array[j+1];
					Array[j] = Array[j] ^ Array[j+1];										
				}
			}
		}
		System.out.print("����������Ԫ��");
		for(int a:Array){//��������
			System.out.print(a + " ");		
		}
	}
	public static void Insert_Sorting(int [] Array){//��������
		int i,j;
		int temp;
		System.out.print("����ǰ������Ԫ��");
		for(int a:Array){//��������
			System.out.print(a + " ");		
		}
		System.out.println();//�س�����
		for(i = 1; i < Array.length; i++){
			temp = Array[i];
			for(j = i - 1; j >= 0; j--){
				if(temp < Array[j]){
					Array[j+1]= Array[j];//����൱�ڽ����Ԫ������λ��
				}
				else
					break;
			}
			Array[j+1] = temp;//�ڶ�Ӧλ���ϲ����¼����Ԫ��Array[i]
		}
		System.out.print("����������Ԫ��");
		for(int a:Array){//��������
			System.out.print(a + " ");		
		}
	}
	public static void Quick_Sorting(int [] Array, int low, int high){//�������򣬲ο�������Ա���Ա��䡷	
		int i, j;
		int index;
		if(low>= high)
			return;
		/*************һ�����򣬸���index=array[i]�Ĵ�С����indexΪ���ޣ� �������ΪС��index������ʹ���index������****************/
		i = low;
		j = high;
		index = Array[i];//�洢Array[i]��index����
		while(i < j){//����������i��j�������������ݷֳ������䣬����j�����������i��������
			while(i < j&& Array[j] >= index)//��֤ǰ�沿��ֵ��С��j��ָ��Ԫ�أ�Ȼ�����εݼ�j
				j--;
			if(i < j)
				Array[i++] = Array[j];//���������˵��Array[j] < index����ô�ͽ�j��ָ���Ԫ�طŵ�i��Ӧ��������ȥ
			while(i < j&& Array[i] < index)//Ȼ��Ա�i��ָ��Ԫ���Ƿ�С��index����iָ����jָ�뿿£
				i++;
			if(i < j)
				Array[j--] = Array[i];//���������˵�� Array[i] >= index����i��ָ���Ԫ���滻��jָ����ָ��λ��
		}
		Array[i] = index;
		/****************************************************************************************************/
		Quick_Sorting(Array, low, i - 1);//ע��high��ֵ
		Quick_Sorting(Array, i+1, high);//ע��low��ֵ		
	}
	
	public static void Merge(int [] Array, int p, int q, int r){//�鲢���򡪡��ϲ����ο�������Ա���Ա��䡷
		int i,j,k,n1,n2;
		n1 = q - p + 1;
		n2 = r - q;
		int []L = new int[n1];
		int []R = new int[n2];
		/**********�����ӱ��ֵ����������L��R��*********/
		for(i = 0,k = p; i<n1; i++, k++){
			L[i] = Array[k];		
		}
		for(i = 0,k = q+1; i<n2; i++, k++){
			R[i] = Array[k];		
		}
		/****************************************/
		
		/**********�Ƚ����ӱ�L��R��С������С˳��ظ���array����*********/
		for(k = p, i=0, j=0; i<n1 && j<n2; k++){
			if(L[i]>R[j]){//���ǽ������У���Ϊ<Ϊ��������
				Array[k] = L[i];
				i++;
			}
			else{
				Array[k] = R[j];
				j++;
			}
		}
		if(i<n1){//����i<n1˵������forѭ��������j>=n2������ֹ�ģ�˵��L��ʣ���ֵ��С��R��Ԫ�أ�ֱ�Ӱ�˳���Ƹ�array����(�������㷨�� L��R�е�Ԫ�ض��������)
			for(j=i; j<n1; j++, k++){
				Array[k]=L[j];
			}
		}
		if(j<n2){//ͬ��
			for(i=j; i<n2; i++, k++){
				Array[k]=R[i];
			}
		}
		/**********************************************/
	}
	public static void Merge_Sorting(int [] Array, int p, int r){//�鲢���򡪡��ݹ黮���ӱ��ϲ�
		if(p<r){		
			int q = (p + r)/2;
			Merge_Sorting(Array, p, q);//�ݹ黮���ӱ�ֱ��Ϊ����Ԫ��Ϊֹ	
			Merge_Sorting(Array, q+1, r);//�ݹ黮���ӱ�ֱ��Ϊ����Ԫ��Ϊֹ	
			Merge(Array, p, q, r);	//�ϲ����ӱ�		
			
		}
	}
	
	public static void Shell_Sorting(int [] array, int length){//ϣ�����򣬼�����,����
		int i,j;
		int h;
		int temp;
		for(h=length/2; h>0; h=h/2){//����hΪ���鳤�����γ�2����ȡ��
			for(i=h; i<length; i++){//ֱ�Ӳ�������
				temp = array[i];//��ֵiλ��ֵ��temp
				for(j=i-h; j>=0; j-=h){//���temp(iλ�ö�Ӧ��������)��j=i-h*n(nΪ����)С���ͽ���temp��j�������ݣ����������һ��ѭ��
					if(temp<array[j]){//����<���ų����������򣬸�Ϊ>��ɽ���
						array[j+h] = array[j];
					}
					else{
						break;
					}
				}
				array[j+h] = temp;//�ظ�tempֵ����Ӧ��j+hλ��
			}
		}
	}
	
	
}
