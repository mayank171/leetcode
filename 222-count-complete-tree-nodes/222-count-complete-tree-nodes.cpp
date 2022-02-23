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
        
        int l= lheight(root);
        int r= rheight(root);
        
        if(l==r)
            return (1<<l)-1;
        
        return 1+check(root->left,ct)+check(root->right,ct);
        
    }
    
    int lheight(TreeNode* root)
    {
        int ct=0;
        while(root)
        {
            ct++;
            root=root->left;
        }
        return ct;
    }
    
    int rheight(TreeNode* root)
    {
        int ct=0;
        while(root)
        {
            ct++;
            root=root->right;
        }
        return ct;
    }
    
public:
    int countNodes(TreeNode* root) {
        
        int ct=0;
        
        if(root==NULL)
            return ct;
        
        ct=check(root,ct);
        
        return ct;
        
    }
};