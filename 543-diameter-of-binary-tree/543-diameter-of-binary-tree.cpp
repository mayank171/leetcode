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
    int check(TreeNode* root,int &ct)
    {
        if(root==NULL)
            return 0;
        
        int l=check(root->left,ct);
        int r=check(root->right,ct);
        
        ct=max(ct,l+r);
        
        return max(l,r)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ct=0;
        check(root,ct);
        
        return ct;
    }
};