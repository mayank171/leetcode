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
    TreeNode* check(TreeNode* root,int n1,int n2)
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        int p,q,r,s;
        p=q=r=s=0;
        
        if(root->val>n1)
        {
            root->left=check(root->left,n1,n2);
            p=1;
        }
        else if(root->val<n1)
        {
            root->right=check(root->right,n1,n2);
            q=1;
        }
        else
        {
            return root;
        }
        
        if(root->val>n2)
        {
            root->left=check(root->left,n1,n2);
            r=1;
        }
        else if(root->val<n2)
        {
            root->right=check(root->right,n1,n2);
            s=1;
        }
        else
        {
            return root;
        }
        
        if(p==1 && r==1)
        {
            return root->left;
        }
        else if(p==1 && s==1)
        {
            return root;
        }    
        else if(q==1 && r==1)
        {
            return root;
        }
        else 
        {
            return root->right;
        }
     
        //return root;
        
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* res=check(root,p->val,q->val);
        
        return res;
        
    }
};