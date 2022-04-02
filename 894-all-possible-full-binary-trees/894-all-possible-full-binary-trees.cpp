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
    
//     vector<TreeNode*> check(int n)
//     {
//         if(n==1)
//         {
//             vector<TreeNode*> ans;
//             ans.push_back(new TreeNode(0));
//             return ans;
//         }
        
//         vector<TreeNode*> ans;
        
//         for(int i=1;i<n;i+=2)
//         {
//             vector<TreeNode*> left=check(i);
//             vector<TreeNode*> right=check(n-i-1);
            
//             for(auto &l:left)
//             {
//                 for(auto &r:right)
//                 {
//                     TreeNode* root=new TreeNode(0);
//                     root->left=l;
//                     root->right=r;
//                     ans.push_back(root);
//                 }
//             }
//         }
//         return ans;
//     }
    vector<TreeNode*> check1(int n)
    {
        vector<TreeNode*> ans;
        if(n==1)
        {
            //vector<TreeNode*> x;
            TreeNode* node=new TreeNode(0);
            ans.push_back(node);
            return ans;
        }
        
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> lft=check1(i);
            vector<TreeNode*> rgt=check1(n-i-1);
            
            for(auto &l:lft)
            {
                for(auto &r:rgt)
                {
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        
        
//        return check(n);
        
        //vector<TreeNode*> ans;
        
        return check1(n);
        
        //return ans;
        
    }
};