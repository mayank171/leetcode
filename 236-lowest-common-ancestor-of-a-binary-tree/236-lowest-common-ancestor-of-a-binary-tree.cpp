/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
//     TreeNode* check(TreeNode* root,int n1,int n2)
//     {
//         if(root==NULL)
//         {
//             TreeNode* temp=NULL;
//             return temp;
//         }
        
//         if(root->val==n1 ||root->val==n2)
//         {
//             return root;
//         }
        
        
//         TreeNode* left=check(root->left,n1,n2);
//         TreeNode* right=check(root->right,n1,n2);
//         if(left==NULL && right==NULL)
//         {
//             return left;
//         }
//         else if(left==NULL && right!=NULL)
//         {
//             return right;
//         }
//         else if(left!=NULL && right==NULL)
//         {
//             return left;
//         }
//         else 
//         {
//             return root;
//         }
        
//     }
private:
    TreeNode* check1(TreeNode* root,int n1,int n2)
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        if(root->val==n1 || root->val==n2)
        {
            return root;
        }
        
        root->left=check1(root->left,n1,n2);
        root->right=check1(root->right,n1,n2);
        
        if(root->left==NULL && root->right==NULL)
        {
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            return root->left;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            return root->right;
        }
        else
        {
            return root;
        }
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//        TreeNode* ans=check(root,p->val,q->val);
       
//        return ans;
        
        TreeNode* res=check1(root,p->val,q->val);
        
        return res;
        
    }
};