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

//     void inorder(TreeNode* root,unordered_set<int> &s)
//     {
//         if(root==NULL)
//             return ;
        
//         inorder(root->left,s);
//         s.insert(root->val);
//         inorder(root->right,s);
//     }
    
//     void preorder(TreeNode* root,unordered_set<int> &s)
//     {
//         if(root==NULL)
//             return ;
        
//         int sum=0;
//         for(auto &it:s)
//         {
//             if(it!=root->val && it>root->val)
//             {
//                 sum+=it;
//             }
//         }    
  
//         root->val+=sum;
//         preorder(root->left,s);
//         preorder(root->right,s);
//     }
    
    int prev=0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        
        
        if(root->right)
            bstToGst(root->right);
        
        root->val=prev+root->val;
        prev=root->val;
        
        if(root->left)
            bstToGst(root->left);
        
        return root;
      
//         unordered_set<int> s;
        
//         TreeNode* cur=root;
        
//         inorder(cur,s);
        
//         preorder(root,s);
        
//         return root;
   
        
    }
};