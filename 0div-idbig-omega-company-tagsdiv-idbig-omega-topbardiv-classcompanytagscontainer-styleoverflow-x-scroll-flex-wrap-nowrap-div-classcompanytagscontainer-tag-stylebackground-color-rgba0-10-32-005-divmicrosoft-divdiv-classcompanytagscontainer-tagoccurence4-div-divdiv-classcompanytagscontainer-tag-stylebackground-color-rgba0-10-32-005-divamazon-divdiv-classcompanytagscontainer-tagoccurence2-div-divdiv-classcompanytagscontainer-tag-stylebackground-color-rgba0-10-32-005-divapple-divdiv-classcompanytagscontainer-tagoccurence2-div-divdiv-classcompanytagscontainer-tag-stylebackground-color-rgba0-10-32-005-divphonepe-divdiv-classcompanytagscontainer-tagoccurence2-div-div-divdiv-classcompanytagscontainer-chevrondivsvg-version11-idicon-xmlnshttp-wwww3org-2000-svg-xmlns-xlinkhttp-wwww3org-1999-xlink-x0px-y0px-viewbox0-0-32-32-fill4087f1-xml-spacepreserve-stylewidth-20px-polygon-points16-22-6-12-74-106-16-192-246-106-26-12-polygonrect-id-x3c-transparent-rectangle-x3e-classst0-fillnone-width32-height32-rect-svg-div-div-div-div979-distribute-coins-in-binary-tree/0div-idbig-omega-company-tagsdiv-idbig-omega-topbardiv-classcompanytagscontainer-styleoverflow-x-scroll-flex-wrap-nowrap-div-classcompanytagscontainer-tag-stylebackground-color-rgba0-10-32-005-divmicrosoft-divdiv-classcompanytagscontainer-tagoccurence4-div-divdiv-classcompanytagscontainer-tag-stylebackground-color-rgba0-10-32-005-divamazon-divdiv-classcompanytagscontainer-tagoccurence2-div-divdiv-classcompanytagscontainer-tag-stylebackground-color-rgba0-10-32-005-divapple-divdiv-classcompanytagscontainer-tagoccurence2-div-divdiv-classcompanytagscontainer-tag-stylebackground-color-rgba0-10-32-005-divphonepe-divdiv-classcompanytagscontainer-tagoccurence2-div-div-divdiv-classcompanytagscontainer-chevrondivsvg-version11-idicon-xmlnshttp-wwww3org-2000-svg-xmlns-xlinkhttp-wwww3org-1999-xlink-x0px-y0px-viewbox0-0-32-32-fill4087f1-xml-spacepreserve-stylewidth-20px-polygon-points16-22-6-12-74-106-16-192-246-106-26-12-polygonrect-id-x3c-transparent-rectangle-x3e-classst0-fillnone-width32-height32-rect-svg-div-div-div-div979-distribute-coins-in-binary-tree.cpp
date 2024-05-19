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
    
    void solve(TreeNode* parent, TreeNode* child, int &ct)
    {
        if(child==NULL)
            return ;
        
        solve(child,child->left,ct);
        solve(child,child->right,ct);
        
        if(child->val>1)
        {
            int extracoins=child->val-1;
            child->val=1;
            parent->val+=extracoins;
            ct+=extracoins;
        }
        else if(child->val<1)
        {
            int neededcoins=1+abs(child->val);
            child->val=1;
            parent->val-=neededcoins;
            ct+=neededcoins;
        }
    }
    
    int distributeCoins(TreeNode* root) {
        
        int ct=0;
        solve(root,root,ct);
        
        return ct;
    }
};