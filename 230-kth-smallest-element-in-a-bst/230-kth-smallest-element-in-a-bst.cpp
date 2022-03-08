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
    void check(TreeNode* root,int& k,int &ans)
    {
        if(root==NULL)
            return ;
        
//         if(root->left==NULL)
//         {
//             k--;
//         }
        
        check(root->left,k,ans);
        if(k>0)
           ans=root->val;
        k--;
        check(root->right,k,ans);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int ans=-1;
        
        check(root,k,ans);
        
        return ans;
        
    }
};