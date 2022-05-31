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
    void inorder(TreeNode* root,vector<int> &v,int &ans)
    {
        if(root==NULL)
        {
            
            int mini=*min_element(v.begin(),v.end());
            int maxi=*max_element(v.begin(),v.end());
            
            ans=max(ans,abs(mini-maxi));
            
            return ;
        }
        
        v.push_back(root->val);
        inorder(root->left,v,ans);
        inorder(root->right,v,ans);
        v.pop_back();
        
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        
        vector<int> v;
        
        int ans=0;
        
        inorder(root,v,ans);

        return ans;
    }
};