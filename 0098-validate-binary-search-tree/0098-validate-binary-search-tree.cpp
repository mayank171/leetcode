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
    
    void solve(TreeNode* root,int &prev,int &flag)
    {
        if(root==NULL)
            return ;
        
        solve(root->left,prev,flag);
        
        if(prev==-1e9)
            prev=root->val;
        else if(prev>=root->val)
        {
            flag*=0;
        }
        else
        {
            prev=root->val;
        }
        
        solve(root->right,prev,flag);
    }
    
    bool isValidBST(TreeNode* root) {
        
        int prev=-1e9;
        int flag=1;
        solve(root,prev,flag);
        
        if(flag==1)
            return true;
        return false;
    }
};