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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> stk;
        
        stk.push(root);
        
        while(!stk.empty())
        {
            TreeNode* node=stk.top();
            stk.pop();
            
            ans.push_back(node->val);
            if(node->right!=NULL)
               stk.push(node->right);
            if(node->left!=NULL)            
            stk.push(node->left);
        }
        
        return ans;
        
    }
};