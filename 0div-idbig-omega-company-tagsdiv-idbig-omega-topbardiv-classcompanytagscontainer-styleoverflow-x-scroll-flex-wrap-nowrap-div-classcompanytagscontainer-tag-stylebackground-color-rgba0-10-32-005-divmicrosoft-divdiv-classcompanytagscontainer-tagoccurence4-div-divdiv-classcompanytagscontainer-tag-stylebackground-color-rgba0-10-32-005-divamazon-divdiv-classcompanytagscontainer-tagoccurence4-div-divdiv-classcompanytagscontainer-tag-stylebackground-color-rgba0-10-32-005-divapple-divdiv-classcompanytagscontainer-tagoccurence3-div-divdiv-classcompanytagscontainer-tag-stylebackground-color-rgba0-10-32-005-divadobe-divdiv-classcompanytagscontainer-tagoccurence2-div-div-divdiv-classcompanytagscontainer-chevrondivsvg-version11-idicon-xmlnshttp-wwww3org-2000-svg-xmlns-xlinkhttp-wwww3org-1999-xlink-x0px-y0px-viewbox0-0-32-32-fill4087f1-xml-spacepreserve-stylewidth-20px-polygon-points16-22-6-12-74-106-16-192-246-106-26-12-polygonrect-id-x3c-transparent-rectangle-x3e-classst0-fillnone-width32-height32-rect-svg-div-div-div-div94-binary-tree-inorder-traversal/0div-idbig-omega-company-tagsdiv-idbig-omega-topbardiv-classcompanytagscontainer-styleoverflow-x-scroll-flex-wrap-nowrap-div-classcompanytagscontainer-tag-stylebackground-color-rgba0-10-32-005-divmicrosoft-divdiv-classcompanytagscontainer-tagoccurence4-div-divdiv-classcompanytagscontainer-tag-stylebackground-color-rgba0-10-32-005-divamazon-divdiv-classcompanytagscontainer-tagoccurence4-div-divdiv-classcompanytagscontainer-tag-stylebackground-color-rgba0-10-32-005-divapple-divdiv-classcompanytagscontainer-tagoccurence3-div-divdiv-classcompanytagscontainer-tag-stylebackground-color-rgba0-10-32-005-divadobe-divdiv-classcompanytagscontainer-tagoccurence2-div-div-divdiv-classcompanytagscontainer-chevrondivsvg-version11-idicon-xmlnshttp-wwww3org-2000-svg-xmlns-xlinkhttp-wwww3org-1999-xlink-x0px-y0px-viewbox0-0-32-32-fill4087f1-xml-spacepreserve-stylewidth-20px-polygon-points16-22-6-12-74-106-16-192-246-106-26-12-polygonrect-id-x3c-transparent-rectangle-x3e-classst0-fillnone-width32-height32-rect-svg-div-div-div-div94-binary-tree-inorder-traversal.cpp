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
    vector<int> inorderTraversal(TreeNode* root) {
        
        TreeNode* cur=root;
        vector<int> ans;
        
        while(cur)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
                continue;
            }
            
            TreeNode* temp=cur->left;
            while(temp->right!=NULL && temp->right!=cur)
            {
                temp=temp->right;
            }
            
            if(temp->right==NULL)
            {
                temp->right=cur;
                cur=cur->left;
            }
            else if(temp->right==cur)
            {
                temp->right=NULL;
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        
        return ans;
    }
};