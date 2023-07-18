class Solution {
public:
    
    int solve(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int x=max(0,solve(root->left,ans));
        int y=max(0,solve(root->right,ans));
        
        ans=max(ans,root->val+x+y);
        return root->val+max(x,y);
    }
    
    int maxPathSum(TreeNode* root) {

        int ans=-1e8;
        solve(root,ans);
        return ans;
    }
};