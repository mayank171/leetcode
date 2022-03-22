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
    void check(TreeNode* root,vector<int> & inorder)
    {
        if(root==NULL)
            return;
        check(root->left,inorder);
        inorder.push_back(root->val);
        check(root->right,inorder);
    }
    
    void check2(TreeNode* root,vector<int> &inorder,int &ind)
    {
        if(root==NULL)
            return;
        check2(root->left,inorder,ind);
        root->val=inorder[ind];
        ind++;
        check2(root->right,inorder,ind);
    }
    
    
public:
    void recoverTree(TreeNode* root) {
        
        vector<int> inorder;
        
        check(root,inorder);
        
        sort(inorder.begin(),inorder.end());
        
        int ind=0;
        
        check2(root,inorder,ind);
        
    }
};