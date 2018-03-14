/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
	vector<int> temp;
    int LevelTravase(TreeNode* root, int level)
    {
        if(root == NULL || level < 0)
            return 0;
        else if(level == 0)
        {
            temp.push_back(root->val);
            return 1;
        }
        return LevelTravase(root->left, level-1) + LevelTravase(root->right, level-1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        for(int level = 0; ; level++)
        {
            if(!LevelTravase(root,level))
                break;
            result.push_back(temp);
            temp.clear();
        }
        return result;
            
    }
 
 
    TreeNode* Find(TreeNode* root, TreeNode*p)//Find the p TreeNode in BST root
    {
        if(root == NULL)
            return NULL;
        else if(p->val < root->val)
        {
            return Find(root->left, p);
        }
        else if(p->val > root->val)
        {
            return Find(root->right, p);
        } vector<vector<int>> result;    
        else
            return root;
    }



/**
@question:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).��

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //��������lowest common ancestor(LCA)�Ĳ��Һ���lowestCommonAncestor,������ݹ�����оֲ�������return����㷵�صĻ��ƣ���ʦ������
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == p || root == q || root == NULL) return root;//1 ��ݴ�����ɧ�ĵط��ڵ�һ���ж���������root�ֳ�������֧�����p��q���������֧����ô���յݹ�����֧����NULL������ʹ��ҷ�֧������
        TreeNode *left = lowestCommonAncestor(root->left, p, q), *right = lowestCommonAncestor(root->right, p, q);//�������������left��right���Ǿֲ�������ÿ����һ�ζ��ᴴ��һ�Σ�����ͨ��//1��//2��֤���ҵ��Ľڵ���㷵�ص��ʼ��root�ڵ��ǲ��lowestCommonAncestor��������ʦ������
        return left && right ? root : left ? left : right;//2  
    }
};