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
    int check(TreeNode* node)
    {
        if(node==NULL)
            return 0;
        
        int l=check(node->left);
        int r=check(node->right);
        
        
        
        if(abs(l-r)>1 || l==-1 || r==-1)
            return -1;
        else
            return max(l,r)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        
        if(check(root)==-1)
            return false;
        else
            return true;
        
 
    }
};