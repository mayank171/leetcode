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
    
    int solve(TreeNode* root,int flag,map<pair<TreeNode*,int>,int> &mp)
    {
        if(root==NULL)
            return 0;
        
        if(mp.find({root,flag})!=mp.end())
            return mp[{root,flag}];
        
        int take=0;
        int nottake=0;
        int total1=0;
        int total2=0;
        
        if(flag==1)
        {
            take=root->val;
            int l=solve(root->left,-1,mp);
            int r=solve(root->right,-1,mp);
            total1=take+l+r;
        }
        int l=solve(root->left,1,mp);
        int r=solve(root->right,1,mp);
        total2=nottake+l+r;
        
        
        return mp[{root,flag}]=max(total1,total2);
    }
    
    int rob(TreeNode* root) {
        
        int flag=1;
        map<pair<TreeNode*,int>,int> mp;
        return solve(root,flag,mp);
        
    }
};