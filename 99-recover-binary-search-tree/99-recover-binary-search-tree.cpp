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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
    TreeNode* third;
    
//     void check(TreeNode* root,vector<int> & inorder)
//     {
//         if(root==NULL)
//             return;
//         check(root->left,inorder);
//         inorder.push_back(root->val);
//         check(root->right,inorder);
//     }
    
//     void check2(TreeNode* root,vector<int> &inorder,int &ind)
//     {
//         if(root==NULL)
//             return;
//         check2(root->left,inorder,ind);
//         root->val=inorder[ind];
//         ind++;
//         check2(root->right,inorder,ind);
//     }
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        
        inorder(root->left);
        if(prev && prev->val>root->val)
        {
            if(first==NULL)
            {
                first=prev;
                second=root;
            }
            else
            {
                third=root;
            }
        }
        
        prev=root;
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        
        
        
//         vector<int> inorder;
        
//         check(root,inorder);
        
//         sort(inorder.begin(),inorder.end());
        
//         int ind=0;
        
//         check2(root,inorder,ind);
        first=second=third=NULL;
        prev=new TreeNode(INT_MIN);
        
        inorder(root);
        
        if(first!=NULL && third!=NULL)
            swap(first->val,third->val);
        else if(first!=NULL && second!=NULL)
        {
            swap(first->val,second->val);
        }
        
    }
};