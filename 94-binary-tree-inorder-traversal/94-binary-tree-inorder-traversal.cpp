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
    
// private:
//     void inorder(TreeNode* root,vector<int> &nodes)
//     {
//         if(root==NULL)
//             return ;
//         else
//         {
//             inorder(root->left,nodes);
//             nodes.push_back(root->val);
//             inorder(root->right,nodes);
//         }
//     }
    
    
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
             }
            else
            {
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur)
                {
                    prev=prev->right;
                }
                
                if(prev->right==NULL)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else
                {
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        
        return ans;
        
    }
};