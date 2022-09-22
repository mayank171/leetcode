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
    
    int solve(TreeNode* root,int &maxi)
    {
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
        {
            maxi=max(maxi,root->val);
            return max(0 ,root->val);
        }
        
        
        int l=solve(root->left,maxi);
        int r=solve(root->right,maxi);
        
        maxi=max(maxi,l+r+root->val);
        
        return max(0,root->val+max(l,r));
    }
    
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        
        return ans;
    }
};