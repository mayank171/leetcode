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
    int check(TreeNode* root,int &maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int l=max(0,check(root->left,maxi));
        int r=max(0,check(root->right,maxi));

        maxi=max(l+r+root->val,maxi);
 
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int maxi=INT_MIN;
        check(root,maxi);
        
        return maxi;
    }
};