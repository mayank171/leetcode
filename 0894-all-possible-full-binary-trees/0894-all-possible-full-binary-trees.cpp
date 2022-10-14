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
    
    vector<TreeNode*> solve(int start,int end)
    {
        if(start==end)
        {
            return {new TreeNode(0)};
        }
        
        
        vector<TreeNode*> ans;
        
        for(int i=start+1;i<=end;i+=2)
        {
            vector<TreeNode*> leftt=solve(1,i-1);
            vector<TreeNode*> rightt=solve(1,end-i);
            
            
            for(auto &it:leftt)
            {
                for(auto &it1:rightt)
                {
                    TreeNode* root=new TreeNode(0);
                    root->left=it;
                    root->right=it1;
                    ans.push_back(root);
                }
            }
            
           
            
            
            
        }
        
        return ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        
        return solve(1,n);
        
    }
};