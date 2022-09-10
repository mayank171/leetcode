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

class pair1
{
    public:
    int isBst;
    long mini;
    long maxi;
};

class Solution {
public:
    
    pair1 solve(TreeNode* root)
    {
        if(root==NULL)
        {
            pair1 p;
            p.isBst=1;
            p.mini=LONG_MAX;
            p.maxi=LONG_MIN;
            return p;
        }
        
        pair1 l=solve(root->left);
        pair1 r=solve(root->right);
        
        
        pair1 cur;
        
        cur.isBst=l.isBst && r.isBst && (l.maxi<root->val && root->val<r.mini);
        if(root->val<l.mini)
            cur.mini=root->val;
        else
            cur.mini=l.mini;
        
        if(root->val>r.maxi)
            cur.maxi=root->val;
        else
            cur.maxi=r.maxi;
        
        
        return cur;
        
    }
    
    
    bool isValidBST(TreeNode* root) {
        
        
        pair1 p=solve(root);
        
        if(p.isBst)
        {
            return true;
        }
        return false;
    }
};