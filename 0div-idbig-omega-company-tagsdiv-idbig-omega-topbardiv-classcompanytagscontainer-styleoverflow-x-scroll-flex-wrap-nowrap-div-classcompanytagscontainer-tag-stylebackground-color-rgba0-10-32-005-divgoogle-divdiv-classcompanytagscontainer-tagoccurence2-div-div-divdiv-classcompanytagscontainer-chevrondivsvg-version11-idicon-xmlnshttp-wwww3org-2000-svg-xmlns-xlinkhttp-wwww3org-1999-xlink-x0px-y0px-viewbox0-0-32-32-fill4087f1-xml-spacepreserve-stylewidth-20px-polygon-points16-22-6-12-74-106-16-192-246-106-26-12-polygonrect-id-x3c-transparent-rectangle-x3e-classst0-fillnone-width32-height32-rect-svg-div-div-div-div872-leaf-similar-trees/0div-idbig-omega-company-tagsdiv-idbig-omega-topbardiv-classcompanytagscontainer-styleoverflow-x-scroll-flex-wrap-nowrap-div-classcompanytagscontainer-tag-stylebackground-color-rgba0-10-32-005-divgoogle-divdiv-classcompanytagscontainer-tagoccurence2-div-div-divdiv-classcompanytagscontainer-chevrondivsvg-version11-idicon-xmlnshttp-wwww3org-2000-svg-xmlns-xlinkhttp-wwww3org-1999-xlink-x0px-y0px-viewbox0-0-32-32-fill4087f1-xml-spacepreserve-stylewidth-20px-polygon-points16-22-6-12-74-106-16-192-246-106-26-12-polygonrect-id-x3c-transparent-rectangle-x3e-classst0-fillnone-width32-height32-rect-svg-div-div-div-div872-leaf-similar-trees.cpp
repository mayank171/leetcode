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
    
    void solve(TreeNode* root,vector<int> &v1)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
           v1.push_back(root->val);
        solve(root->left,v1);
        solve(root->right,v1);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1;
        solve(root1,v1);
        vector<int> v2;
        solve(root2,v2);
        
        for(auto &it:v1)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        
        for(auto &it:v2)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        
        
        
        
        if(v1.size()!=v2.size())
            return false;
        
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
                return false;
        }
        
        return true;
    }
};