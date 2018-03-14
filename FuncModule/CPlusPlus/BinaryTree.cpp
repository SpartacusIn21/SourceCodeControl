/*
FileName: BinaryTree.cpp
Create Time:   2015/09/03
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference:  https://leetcode.com/problems/minimum-depth-of-binary-tree/   
Question:Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Description: ��1������������С��ȡ������ȵݹ��㷨��
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//�����������С���
//����1
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        //�����������Ϊ�˱�����Ϊĳ������Ϊ�ն�ֱ�ӷ����㣬����ʱ���������������Ҫ����Ϊ����Ҷ�ڵ㣬������С��ȵ�ʱ����ȱ���������ȵ�ʱ���ȱ
		if(!root->left) return 1 + minDepth(root->right);//
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));//��������ֻ�ᱻ���ִ��һ��
    }
};
//����2����Ч�㷨
class Solution {
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		queue<TreeNode*> Q;
		Q.push(root);
		int i = 0;
		while (!Q.empty()) {
			i++;
			int k = Q.size();
			for (int j=0; j<k; j++) {
				TreeNode* rt = Q.front();
				if (rt->left) Q.push(rt->left);
				if (rt->right) Q.push(rt->right);
				Q.pop();
				if (rt->left==NULL && rt->right==NULL) return i;
			}
		}
		return -1; //For the compiler thing. The code never runs here.
	}
};


//��������������ȣ�����1�ͷ���2��ʵ��һ���ģ�ֻ����ʽ��΢�е㲻ͬ����
//����1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
/*         if(!root->left) return 1 + maxDepth(root->right);//�����������Ϊ�˱�����Ϊĳ������Ϊ�ն�ֱ�ӷ����㣬����ʱ���������������Ҫ����Ϊ����Ҷ�ڵ㣬������С��ȵ�ʱ����ȱ���������ȵ�ʱ���ȱ
        if(!root->right) return 1 + maxDepth(root->left); */
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
//����2
class Solution {
public:
    int maxDepth(TreeNode *root) {
        return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;//���ú�������
    }
};