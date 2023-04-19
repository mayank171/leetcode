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
    
    void solve(TreeNode* root,char last,int &maxi,int ct)
    {
        if(root==NULL)
        {
            maxi=max(maxi,ct);
            return;
        }   
        
        int l=0;
        int r=0;
        
        if(last=='-')
        {
            solve(root->left,'l',maxi,ct+1);
            solve(root->right,'r',maxi,ct+1);
        }
        else if(last=='r')
        {
            solve(root->left,'l',maxi,ct+1);
            solve(root->right,'r',maxi,1);
        }
        else
        {
            solve(root->right,'r',maxi,ct+1);
            solve(root->left,'l',maxi,1);    
        }
    }
    
    int longestZigZag(TreeNode* root) {
        
        char last='-';
        int maxi=0;
        solve(root,last,maxi,0);
        return maxi-1;
    }
};