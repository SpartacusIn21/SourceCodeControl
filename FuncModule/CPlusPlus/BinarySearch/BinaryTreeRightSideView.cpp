/*
FileName: BinaryTreeRightSizeView.cpp
Create Time:   2015/09/04
Modify Time: 
Author: Chen Yangchun
Owner:  Chen Yangchun
Place:  �Ϻ���ͨ��ѧ����У��΢����¥301��
Reference: https://leetcode.com/problems/binary-tree-right-side-view/
Description: ��1��ʹ�ò�α����㷨������ұ����󿴵��Ķ������Ľ��ֵ��
*/
/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {//BFS�㷨����α���
        if(!root)return ret;
		queue<TreeNode*>mQ;//�½�����
        vector<int> ret;//�����洢������        
        mQ.push(root);//�����
        while(!mQ.empty()){//�����в�Ϊ��ʱ
            ret.push_back(mQ.back()->val);//�����������һ��Ԫ��push_back��vector�У���Ϊ���һ���ڵ���ʼ���Ǹò��д��ұ��ܿ������Ǹ�Ԫ�أ������ɺ���ı���������
            for(int i=mQ.size();i>0;i--){
                TreeNode *tn=mQ.front();
                mQ.pop();
                if(tn->left)mQ.push(tn->left);//������������ӣ�������������ӣ��ɱ�֤���������һ��Ԫ��������Ҫ���
                if(tn->right)mQ.push(tn->right);
            }
        }
        return ret;
    }
};