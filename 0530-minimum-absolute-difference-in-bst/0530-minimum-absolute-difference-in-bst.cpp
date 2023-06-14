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
    
    void solve(TreeNode* root,int &ans,int &first,int &second)
    {
        if(root==NULL)
            return ;
        
//         if(root->left==NULL)
//         {
//             if(first==-1)
//                 first=root->val;
//             else if(second==-1)
//                 second=root->val;
            
//             if(first!=-1 && second!=-1)
//             {
//                ans=min(ans,abs(first-second));
//                 first=second;
//                 second=-1;
//             }
            
//             solve(root->right,ans,first,second);
       
//             return;
//         }
        
        solve(root->left,ans,first,second);
        
        if(first==-1)
            first=root->val;
        else if(second==-1)
            second=root->val;
        else
        {
            first=second;
            second=root->val;

        }
        if(first!=-1 && second!=-1)
        {
            ans=min(ans,abs(first-second));
            first=second;
            second=-1;
        }
        
        solve(root->right,ans,first,second);
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        int ans=1e9;
        int first=-1;
        int second=-1;
        solve(root,ans,first,second);
        return ans;
    }
};