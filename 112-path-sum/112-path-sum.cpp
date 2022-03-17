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
    void check(TreeNode* root,int &sum,int &flag)
    {
        if(root==NULL)
            return ;
        
   
            sum-=root->val;
            if(sum==0 && root->left==NULL && root->right==NULL)
            {
                flag=1;
                return ;
            }
       
        
        check(root->left,sum,flag);
        if(flag==1)
            return ;
     
        cout<<sum<<endl;
        
        check(root->right,sum,flag);
        if(flag==1)
            return ;
        cout<<sum<<endl;
        sum+=root->val;
      
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return false;
        
        if(root->val==targetSum && root->left==NULL && root->right==NULL)
            return true;
        
        
        //int c=0;
        int flag=0;
        check(root,targetSum,flag);
        
        if(flag==0)
            return false;
        else
            return true;
    }
};