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
    
    int solve(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return 1;
        }
        
        int lc=solve(root->left,ans);
        int rc=solve(root->right,ans);
        
        if(lc==1 && rc==1)
        {
            return -1;
        }
        else if(lc==-1 || rc==-1)
        {
            ans++;
            return 0;
        }
        else if((lc==0 && rc==1) || (lc==1 && rc==0))
        {
            return 1;
        }
        else if((lc==0 && rc==-1)|| (lc==-1 && rc==0))
        {
            ans++;
            return 0;
        }
        return 1;
    }
    
    int minCameraCover(TreeNode* root) {
        
        int ans=0;
        int x=solve(root,ans);
        if(x==-1)
            ans++;
        return ans;
    }
};