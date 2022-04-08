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
private:
    
    void check(TreeNode* root,int &ans,int k)
    {
        if(root==NULL)
        {
            cout<<k<<endl;
            ans+=k;
            return ;
        }
        
        // if(root->left==NULL && root->right==NULL)
        // {
        //     cout<<k<<endl;
        //     ans+=k;
        //     return ;
        // }
        
        k=k*10+root->val;
        cout<<k<<endl;
        
        if(root->left==NULL && root->right==NULL)
        {
            cout<<k<<endl;
            ans+=k;
            return ;
        }
        
        if(root->left!=NULL)
        check(root->left,ans,k);
        
        if(root->right!=NULL)
        check(root->right,ans,k);
        
    }
    
public:
    int sumNumbers(TreeNode* root) {
        
        int ans=0;
        int k=0;
        
        check(root,ans,k);
        
        return ans;
    }
};