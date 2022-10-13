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

    int solve(TreeNode* root,int x)
    {
        if(root==NULL)
            return 0;
        
        
        int ct=0;
        if(root->val>=x)
        {
            ct++;
        }
        
        ct+=solve(root->left,max(root->val,x));
        ct+=solve(root->right,max(root->val,x));
        
        return ct;
    }
    
    
    int goodNodes(TreeNode* root) {
        
        return solve(root,root->val);
        
    }
};