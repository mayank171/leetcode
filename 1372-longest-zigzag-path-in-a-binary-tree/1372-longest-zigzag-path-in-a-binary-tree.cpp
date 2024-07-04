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
    
    void solve(TreeNode* root,char str,int ans,int &maxi)
    {
        if(root==NULL)
        {
            maxi=max(maxi,ans);
            return ;
        }
        
        if(str=='-')
        {
            solve(root->left,'l',ans+1,maxi);
            solve(root->right,'r',ans+1,maxi);
        }
        else if(str=='l')
        {
            solve(root->right,'r',ans+1,maxi);
            solve(root->left,'l',1,maxi);
        }
        else
        {
            solve(root->left,'l',ans+1,maxi);
            solve(root->right,'r',1,maxi);    
        }
    }
    
    int longestZigZag(TreeNode* root) {
        
        char str='-';
        int ans=0;
        int maxi=0;
        solve(root,str,ans,maxi);
        return maxi-1;
    }
};