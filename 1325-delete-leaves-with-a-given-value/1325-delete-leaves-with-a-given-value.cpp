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
    
    void inorder(TreeNode* &root,int target)
    {
        if(root==NULL)
        {
            return ;
        }
        
        inorder(root->left,target);
        if(root->val==target && root->left==NULL && root->right==NULL)
        {
            root=NULL;
            return ;
        }
        inorder(root->right,target);
        if(root->val==target && root->left==NULL && root->right==NULL)
        {
            root=NULL;
            return ;
        }
        
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        inorder(root,target);
        
        return root;
        
    }
};