/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
        else
            return root;
    }



/**
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
        
        if (root == p || root == q || root == NULL) return root;//1
        TreeNode *left = lowestCommonAncestor(root->left, p, q), *right = lowestCommonAncestor(root->right, p, q);//�������������left��right���Ǿֲ�������ÿ����һ�ζ��ᴴ��һ�Σ�����ͨ��//1��//2��֤���ҵ��Ľڵ���㷵�ص��ʼ��root�ڵ��ǲ��lowestCommonAncestor��������ʦ������
        return left && right ? root : left ? left : right;//2
    }
};