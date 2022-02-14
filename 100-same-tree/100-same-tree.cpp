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
    void check(TreeNode* p,TreeNode* q,int &flag)
    {
        if(p==NULL && q!=NULL)
        {
            flag=1;
            return ;
        }
        else if(p!=NULL && q==NULL)
        {
            flag=1;
            return ;
        }
        else if(p==NULL && q==NULL)
        {
            return ;
        }
        
        if(p->val != q->val)
        {
            flag=1;
            return ;
        }
        
        check(p->left,q->left,flag);
        check(p->right,q->right,flag);
        
        
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        int flag=0;
        check(p,q,flag);
        
        if(flag==1)
            return false;
        
        return true;
        
    }
};