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
   
    void solve(TreeNode* root,int cur,int j,int &ans)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL && root->right==NULL)
        {
            cur=pow(10,1)*cur+root->val;
           // cout<<cur<<endl;
            ans+=cur;
            return ;
        }

        cur=pow(10,1)*cur+root->val;
       // cout<<cur<<endl;
        solve(root->left,cur,j+1,ans);
        solve(root->right,cur,j+1,ans);
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        int ans=0;
        solve(root,0,0,ans);
        return ans;

    }
};