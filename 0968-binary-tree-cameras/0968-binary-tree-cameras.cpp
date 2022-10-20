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
    
    int solve(TreeNode* root,int &ct)
    {
        if(root==NULL)
            return 1;
        
        if(root->left==NULL && root->right==NULL)
            return -1;
        
        int lft=solve(root->left,ct);
        int rgt=solve(root->right,ct);
        
        
        if(lft==-1 || rgt==-1)
        {
            ct++;
            return 0;
        }
        else if(lft==0 && rgt==0)
        {
            return 1;
        }
        else if(lft==0 && rgt==1)
        {
            return 1;
        }
        else if(lft==1 && rgt==0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int ans=0;
        int x=solve(root,ans);
        
        if(x==-1)
            ans++;
        return ans;
    }
};