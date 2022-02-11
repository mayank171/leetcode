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
        
        
//        vector<int> nodes;
//        inorder(root,nodes);
        
//         return nodes;
        
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> stk;
        
        stk.push(root);
        
        int k=0;
        
        while(!stk.empty())
        {
            TreeNode* node=stk.top();
            
            while(node->left!=NULL && k==0)
            {
                node=node->left;
                stk.push(node);
            }
            
            TreeNode* node1=stk.top();
            stk.pop();
            
            ans.push_back(node1->val);
            
            if(node1->right!=NULL)
            {
                k=0;
                stk.push(node1->right);
            }
            else
            {
                k=-10001;       //pointer to remind don't go to the upper while loop
            }
        }
        
        return ans;
       
        
    }
};