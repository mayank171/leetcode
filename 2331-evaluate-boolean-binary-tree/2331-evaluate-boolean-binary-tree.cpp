/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int check(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        
        int l=check(root->left);
        int r=check(root->right);
        
        if(root->val==2)
        {
            if(l==0 && r==0)
                return 0;
            else
                return 1;
        }
        else
        {
            if(l==1 && r==1)
                return 1;
            else
                return 0;
        }
        
    }
    
    bool evaluateTree(TreeNode* root) {
        
        return check(root);
        
    }
};