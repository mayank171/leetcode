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
    
    pair<int,int> depth(TreeNode* root,int &flag)
    {
        if(root==NULL)
            return {0,0};
        
        if(root->left==NULL && root->right==NULL)
        {
            flag=1;
            return {1,1};
        }
        
        auto l=depth(root->left,flag);
        auto r=depth(root->right,flag);
        
        if(l.second==1 && r.second==1)
        {
            return {1+min(l.first,r.first),1};
        }
        else if(l.second==1)
        {
            return {1+l.first,1};             
        }
        else if(r.second==1)
        {
            return {1+r.first,1};             
        }
        return {1e9,0};
    }
    
    int minDepth(TreeNode* root) {
        int flag=0;
        auto it= depth(root,flag);
        return it.first;
    }
};