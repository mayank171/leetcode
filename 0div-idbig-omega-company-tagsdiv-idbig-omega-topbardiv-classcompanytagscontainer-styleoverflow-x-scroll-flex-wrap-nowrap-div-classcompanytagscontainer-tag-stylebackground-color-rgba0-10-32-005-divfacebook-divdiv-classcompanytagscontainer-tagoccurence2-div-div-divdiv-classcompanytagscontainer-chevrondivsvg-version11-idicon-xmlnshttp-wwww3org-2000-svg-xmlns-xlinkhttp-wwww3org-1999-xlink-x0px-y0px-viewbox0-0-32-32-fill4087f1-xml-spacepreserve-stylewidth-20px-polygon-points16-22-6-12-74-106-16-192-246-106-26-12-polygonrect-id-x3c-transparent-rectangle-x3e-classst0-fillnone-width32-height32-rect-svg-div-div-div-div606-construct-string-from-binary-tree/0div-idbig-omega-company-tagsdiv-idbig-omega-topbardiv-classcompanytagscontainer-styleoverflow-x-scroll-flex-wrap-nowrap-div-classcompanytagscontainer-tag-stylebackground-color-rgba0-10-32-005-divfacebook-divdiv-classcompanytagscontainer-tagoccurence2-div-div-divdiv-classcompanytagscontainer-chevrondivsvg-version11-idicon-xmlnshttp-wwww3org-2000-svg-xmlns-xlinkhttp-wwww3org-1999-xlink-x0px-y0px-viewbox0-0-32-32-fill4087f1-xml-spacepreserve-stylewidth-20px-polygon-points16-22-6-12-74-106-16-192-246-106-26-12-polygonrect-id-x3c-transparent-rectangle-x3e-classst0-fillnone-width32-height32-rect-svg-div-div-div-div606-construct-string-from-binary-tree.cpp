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
    
    void solve(TreeNode* root,string &ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        string num=to_string(root->val);
        
        
        if(root->left==NULL && root->right==NULL)
        {
          //  ans+='(';
            ans+=num;
          //  ans+=')';
            return ;
        }
        else if(root->left==NULL)
        {
            ans+=num;
            ans+="()";
            ans+='(';
            solve(root->right,ans);
            ans+=')';
        }
        else if(root->right==NULL)
        {
            ans+=num;
            ans+='(';
            solve(root->left,ans);
            ans+=')';
        }
        else
        {
            ans+=num;
            ans+='(';
            solve(root->left,ans);
            ans+=')';
            ans+='(';
            solve(root->right,ans);
            ans+=')';
        }
    }
    
    string tree2str(TreeNode* root) {
        
        string ans="";
        
        solve(root,ans);
        
        return ans;
    }
};