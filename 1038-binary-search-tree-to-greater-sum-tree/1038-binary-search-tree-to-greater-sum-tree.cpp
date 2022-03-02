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
    int tp;
    void inorder(TreeNode* root,unordered_set<int> &s)
    {
        if(root==NULL)
            return ;
        
        inorder(root->left,s);
        s.insert(root->val);
        inorder(root->right,s);
    }
    
    void preorder(TreeNode* root,unordered_set<int> &s)
    {
        if(root==NULL)
            return ;
        
        int sum=0;
        for(auto &it:s)
        {
            if(it!=root->val && it>root->val)
            {
                sum+=it;
            }
        }    
  
        root->val+=sum;
        preorder(root->left,s);
        preorder(root->right,s);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        
      
        unordered_set<int> s;
        
        TreeNode* cur=root;
        
        inorder(cur,s);
        
        preorder(root,s);
        
        return root;
        
//         if(root==NULL)
//             return root;
//         else
//         {
//             TreeNode* t=new TreeNode();
//             t=bstToGst(root->right);
//             root->val=root->val+tp;
//             if(t!=NULL)
//             {
//                 root->val=root->val+t->val;
                
//             }
               
//             if(root->left==NULL)
//             {
//                 return root;
//             }
                
//             else
//             {
             
                
//                 root->left->val=root->left->val+root->val;
//                 tp=root->left->val;
//                 TreeNode* p=bstToGst(root->left);
//                 //root->val=root->val+t;
//                 cout<<root->val<<" "<<tp<<" ";
//             }
            
//         }
//         return root;
        
    }
};