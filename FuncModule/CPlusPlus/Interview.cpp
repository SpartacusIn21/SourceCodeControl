��Դ���������� - ������ 
���ӣ�http://blog.jobbole.com/52144/

�������ڱ������������ǰ 10 ���㷨��صĸ���һ�ͨ��һЩ�򵥵�������������Щ���������ȫ������Щ������Ҫ�����Ŭ�����������б�ֻ����Ϊһ�����ܡ����Ľ���Java�ĽǶȿ����⣬�����������Щ���

1. �ַ���
2. ����
3. ��
4. ͼ
5. ����
6. �ݹ� vs. ����
7. ��̬�滮
8. λ����
9. ��������
10. �������

1. �ַ���

���IDEû�д����Զ���ȫ���ܣ�������Ӧ�ü�ס�������Щ������

toCharArray() // ����ַ�����Ӧ��char����
Arrays.sort()  // ��������
Arrays.toString(char[] a) // ����ת���ַ���
charAt(int x) // ���ĳ�����������ַ�
length() // �ַ�������
length // �����С


2. ����

��Java�У������ʵ�ַǳ��򵥣�ÿ���ڵ�Node����һ��ֵval��ָ���¸��ڵ������next��

class Node {
      int val;
      Node next;
 
Node(int x) {
      val = x;
      next = null;
      }
}

��������������Ӧ����ջStack�Ͷ���Queue��

ջ��

class Stack{
      Node top;
 
      public Node peek(){
            if(top != null){
            return top;
            }
 
      return null;
}
 
public Node pop(){
      if(top == null){
            return null;
      }else{
            Node temp = new Node(top.val);
            top = top.next;
            return temp;
      }
}
 
public void push(Node n){
      if(n != null){
      n.next = top;
      top = n;
      }
    }
}

���У�

class Queue{
    Node first, last;
 
    public void enqueue(Node n){
        if(first == null){
            first = n;
            last = first;
        }else{
            last.next = n;
            last = n;
        }
    }
 
    public Node dequeue(){
        if(first == null){
            return null;
        }else{
            Node temp = new Node(first.val);
            first = first.next;
            if(last == temp) last = first;
            return temp;
        }    
    }
}


3. ��

�������ͨ����ָ��������ÿ���ڵ㶼����һ�����ӽڵ���Һ��ӽڵ㣬������������

class TreeNode{
    int value;
    TreeNode left;
    TreeNode right;
}

������������ص�һЩ���

ƽ�� vs. ��ƽ�⣺ƽ��������У�ÿ���ڵ����������������������Ϊ1��1��0����
����������Full Binary Tree������Ҷ�ӽڵ���Ϊ��ÿ���ڵ㶼���������ӡ�
������������Perfect Binary Tree�����Ǿ����������ʵ��������������е�Ҷ�ӽڵ㶼����ͬ����Ȼ���ͬһ��Σ���ÿ�����ڵ㶼�������������ӡ�
��ȫ��������Complete Binary Tree�����������У����ܳ������һ����ÿһ�㶼����ȫ�����������нڵ㶼���뾡�������󿿡�

����ע������������Ҳ��Լ��Ϊ��ȫ��������������������һ��������һ�����ڸ�����ȵ�����ͼ����Ϊÿ���˶�һ������������ĸ����ȫ���������Կ����ǿ��������ɶ������󿿵�Ҷ�ӽڵ�����������������ʣ��������������������������𣿣��ο���http://xlinux.nist.gov/dads/HTML/perfectBinaryTree.html��


4. ͼ

ͼ��ص�������Ҫ�������������������depth first search���͹������������breath first search����

������һ���򵥵�ͼ�������������ʵ�֡�

1) ����GraphNode

class GraphNode{
     int val;
      GraphNode next;
      GraphNode[] neighbors;
      boolean visited;
 
      GraphNode(int x) {
            val = x;
      }
 
      GraphNode(int x, GraphNode[] n){
      val = x;
      neighbors = n;
}
 
public String toString(){
      return "value: "+ this.val;
      }
}

2) ����һ������Queue

class Queue{
      GraphNode first, last;
 
      public void enqueue(GraphNode n){
            if(first == null){
                  first = n;
                  last = first;      
            }else{
                  last.next = n;
                  last = n;
            }
      }
 
public GraphNode dequeue(){
      if(first == null){
            return null;
      }else{
            GraphNode temp = new GraphNode(first.val, first.neighbors);
            first = first.next;
            return temp;
      }
   }
}

3) �ö���Queueʵ�ֹ����������

public class GraphTest {
 
      public static void main(String[] args) {
            GraphNode n1 = new GraphNode(1);
            GraphNode n2 = new GraphNode(2);
            GraphNode n3 = new GraphNode(3);
            GraphNode n4 = new GraphNode(4);
            GraphNode n5 = new GraphNode(5);
 
            n1.neighbors = new GraphNode[]{n2,n3,n5};
            n2.neighbors = new GraphNode[]{n1,n4};
            n3.neighbors = new GraphNode[]{n1,n4,n5};
            n4.neighbors = new GraphNode[]{n2,n3,n5};
            n5.neighbors = new GraphNode[]{n1,n3,n4};
 
            breathFirstSearch(n1, 5);
      }
 
public static void breathFirstSearch(GraphNode root, int x){
      if(root.val == x)
            System.out.println("find in root");
 
      Queue queue = new Queue();
      root.visited = true;
      queue.enqueue(root);
 
      while(queue.first != null){
            GraphNode c = (GraphNode) queue.dequeue();
            for(GraphNode n: c.neighbors){
                  if(!n.visited){
                        System.out.print(n + " ");
                        n.visited = true;
                        if(n.val == x)
                              System.out.println("Find "+n);
                        queue.enqueue(n);
                     }
               }
          }
     }
}

5. ����

�����ǲ�ͬ�����㷨��ʱ�临�Ӷȣ������ȥwiki��һ����Щ�㷨�Ļ���˼�롣


���⣬������һЩʵ��/��ʾ��

���Ӿ�ֱ�۸��� 7 �ֳ��õ������㷨��
����Ƶ�� 6 ������ʾ 15 �������㷨��


6. �ݹ� vs. ����

�Գ���Ա��˵���ݹ�Ӧ����һ������������˼�루a built-in thought��������ͨ��һ���򵥵�������˵����

���⣺ ��n��̨�ף�һ��ֻ����1����2�������ж������߷���

����1:�ҵ�����ǰn��̨�׺�ǰn-1��̨��֮��Ĺ�ϵ��

Ϊ������n��̨�ף�ֻ�����ַ�������n-1��̨����1���ߵ����n-2��̨�״���2���ߵ������f(n)��������n��̨�׵ķ���������ôf(n) = f(n-1) + f(n-2)��

f(0) = 0;
f(1) = 1;

����2: ȷ����ʼ��������ȷ�ġ�

public static int f(int n){
     if(n <= 2) return n;
     int x = f(n-1) + f(n-2);
     return x;
}

�ݹ鷽����ʱ�临�Ӷ���n��ָ��������Ϊ�кܶ�����ļ��㣬���£�

f(5)
f(4) + f(3)
f(3) + f(2) + f(2) + f(1)
f(2) + f(1) + f(1) + f(0) + f(1) + f(0) + f(1)
f(1) + f(0) + f(1) + f(1) + f(0) + f(1) + f(0) + f(1)

ֱ�ӵ��뷨�ǽ��ݹ�ת��Ϊ������

public static int f(int n) {
 
	if (n <= 2){
	return n;
}
 
	int first = 1, second = 2;
	int third = 0;
 
	for (int i = 3; i <= n; i++) {
		third = first + second;
		first = second;
		second = third;
	}
 
	return third;
}

��������Ӷ��ԣ��������ѵ�ʱ����٣������Ҳ�뿴��Recursion vs Iteration��


7. ��̬�滮

��̬�滮�ǽ��������Щ����������ļ�����

һ���������ͨ����С������Ľ�����������������ע������������Ž������������������Ž⣬Ҳ���������ӽṹ���ʣ���
��Щ������Ľ������Ҫ�����Σ�����ע��Ҳ�����������ص����ʣ���
������Ľ�洢��һ�ű�������ÿ��������ֻ�ü���һ�Ρ�
��Ҫ����Ŀռ��Խ�ʡʱ�䡣

��̨��������ȫ����������������ʣ���˿����ö�̬�滮���������

public static int[] A = new int[100];
 
public static int f3(int n) {
	if (n <= 2)
	A[n]= n;
 
	if(A[n] > 0)
return A[n];
	else
		A[n] = f3(n-1) + f3(n-2);//store results so only calculate once!
	return A[n];
}

8. λ����

λ��������

�� 	��	���	����	����	�� 
1|0=1	1&0=0	1^0=1	0010<<2=1000	1100>>2=0011	~1=0


��ø�������n�ĵ�iλ��( i �� 0 �����������ұ߿�ʼ)

public static boolean getBit(int num, int i){
	int result = num & (1<<i);
 
	if(result == 0){
		return false;
	}else{
		return true;
}

���磬�������10�ĵ�2λ��

i=1, n=10
1<<1= 10
1010&10=10
10 is not 0, so return true;

9. ��������

���������ص�����ͨ����Ҫ�ܺõĹ滮�˽����⣨formatting the problem��������պ���һ����������ļ����ӣ�

һ����������50���ˣ���ô������������������ͬ�ĸ����Ƕ��٣��������������ʵ��Ҳ����һ��365�죩

����ĳЩ����ĸ��ʺܶ�ʱ�򶼿���ת�����ȼ���������档�������������ǿ��Լ������������ն�������ͬ�ĸ��ʣ�Ҳ���ǣ�365/365 * 364/365 * 363/365 * ... * (365-49)/365����������������������ͬ�ĸ��ʾ���1 �C ���ֵ��

public static double caculateProbability(int n){
	double x = 1;
 
	for(int i=0; i<n; i++){
		x *=  (365.0-i)/365.0;
	}
 
	double pro = Math.round((1-x) * 100);
	return pro/100;
}

calculateProbability(50) = 0.97

10. �������

��Ϻ����е��������ڴ����Ƿ�ؼ���