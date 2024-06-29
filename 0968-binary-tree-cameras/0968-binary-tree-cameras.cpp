class Solution {
public:

   int solve(TreeNode* root,int &ans)
   {
       if(root==NULL)
           return 0;
       
       int l=solve(root->left,ans);
       int r=solve(root->right,ans);
       
       if(l==-1 || r==-1)
       {
           ans++;
           return 1;
       }
       else if(l==0 && r==0)
       {
           return -1;
       }
       else
       {
           return 0;
       }
       
   }

    int minCameraCover(TreeNode* root) {
        
        int ans=0;
        int res=solve(root,ans);
        
        if(res==-1)
            return ans+1;
        return ans;
    }
};