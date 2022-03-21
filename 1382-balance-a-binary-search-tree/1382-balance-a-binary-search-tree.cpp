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
    void inorder(TreeNode* root,vector<int>& v)
    {
        if(root==NULL)
            return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    TreeNode* create(int val)
    {
        TreeNode* temp1=new TreeNode();
        temp1->val=val;
        temp1->left=NULL;
        temp1->right=NULL;
        return temp1;
    }
    
    TreeNode* insert(TreeNode* temp,int val)
    {
        if(temp==NULL)
        {
              temp=create(val);
        }
        else if(temp->val>val)
        {
            temp->left=insert(temp->left,val);
        }
        else
        {
            temp->right=insert(temp->right,val);
        }
        
        return temp;
    }
    
    void check1(TreeNode* temp,vector<int> &v,int start,int end)
    {
         if(temp==NULL)
             return;
        
        
         if(start<=end)
         {
             int mid=(start+end)/2;
             TreeNode* temp1=new TreeNode();
                 
             
             if(temp!=NULL && v[mid]<temp->val)
             {
                 temp1->val=v[mid];
                 temp1->left=NULL;
                 temp1->right=NULL;
                 temp->left=temp1;
                 // if(temp->left)
             check1(temp->left,v,start,mid-1);
            // if(temp->right)
             check1(temp->left,v,mid+1,end);
             }
             else  if(temp!=NULL && v[mid]>temp->val)
             {
                 temp1->val=v[mid];
                 temp1->left=NULL;
                 temp1->right=NULL;
                 temp->right=temp1;
                 // if(temp->left)
             check1(temp->right,v,start,mid-1);
            // if(temp->right)
             check1(temp->right,v,mid+1,end);
                 
             }
             
            
         }
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        
        inorder(root,v);
        
        TreeNode* temp=new TreeNode();
        
        temp->val=v[v.size()/2];
        temp->left=NULL;
        temp->right=NULL;
        
        check1(temp,v,0,v.size()/2-1);
        check1(temp,v,v.size()/2+1,v.size()-1);
        
        return temp;
    }
};