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
public:
   
    
    void preorder(TreeNode* root)
    {
        if(root==NULL)
            return ;
        
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
        
    }
    
    vector<TreeNode*> solve(int start,int end)
    {
        if(end<1 || start>end)
            return {NULL};
        if(start==end)
        {
            return {new TreeNode(start)};
        }
        
        if(end-start==1)
        {
            TreeNode* root=new TreeNode();
            root->val=start;
            root->right=new TreeNode(end);
            TreeNode* root1=new TreeNode();
            root1->val=end;
            root1->left=new TreeNode(start);
            
            return {root,root1};
        }
        
        
        vector<TreeNode*> ans;
        
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> leftt=solve(start,i-1);
            vector<TreeNode*> rightt=solve(i+1,end);
            
            for(auto &it1:leftt)
            {
                for(auto &it2:rightt)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=it1;
                    root->right=it2;
                    
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
       return solve(1,n);
        
    }
};












