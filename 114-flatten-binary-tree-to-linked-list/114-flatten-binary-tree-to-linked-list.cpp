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
    void check(TreeNode* root)
    {
        if(root==NULL)
            return ;
        
        if(root->left==NULL && root->right==NULL)
            return ;
        
        
        check(root->left);
        TreeNode* temp=root;
     
        
        if(root->right!=NULL)
           temp=root->right;
        else
        {
            root->right=root->left;
            root->left=NULL;
            return;
        }

        root->right=root->left;
        root->left=NULL;
        TreeNode* temp1=root;
        
        
        while(temp1->right!=NULL)
        {
            temp1=temp1->right;
        }
        
        temp1->right=temp;
        check(root->right);
    }
public:
    void flatten(TreeNode* root) {
        
        check(root);
        
    }
};