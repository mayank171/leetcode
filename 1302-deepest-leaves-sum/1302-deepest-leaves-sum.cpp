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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int l=height(root->left);
        int r=height(root->right);
        
        return max(l,r)+1;
    }
    
    void check(TreeNode* root,int ct,int h,int &sum)
    {
        if(root==NULL)
            return ;
        
        if(ct==h-1)
            sum+=root->val;
        
    
        check(root->left,ct+1,h,sum);
        
        
        check(root->right,ct+1,h,sum);
        
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int h=height(root);
        
        int ct=0;
        int sum=0;
        
        check(root,ct,h,sum);
        
        return sum;
    }
};