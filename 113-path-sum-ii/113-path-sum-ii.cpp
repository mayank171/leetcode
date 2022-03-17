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
    void check(TreeNode* root,int &ct,int targetSum,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(root==NULL)
            return ;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val+ct==targetSum)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return ;
        }
        
       
        ct+=root->val;
        temp.push_back(root->val);
        check(root->left,ct,targetSum,temp,ans);
        temp.pop_back();
        ct-=root->val;
        
        ct+=root->val;
        temp.push_back(root->val);
        check(root->right,ct,targetSum,temp,ans);
        temp.pop_back();
        ct-=root->val;
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        if(root==NULL)
            return ans;
        
        // if(root->left!=NULL && root->right==NULL && root->left->left==NULL && root->left->right==NULL)
        // {
        //     if(root->val+root->left->val==targetSum)
        //     {
        //         temp.push_back(root->val);
        //         temp.push_back(root->left->val);
        //         ans.push_back(temp);
        //     }
        //     return ans;
        // }
        // else if(root->left==NULL && root->right!=NULL && root->right->left==NULL && root->right->right==NULL)
        // {
        //     if(root->val+root->right->val==targetSum)
        //     {
        //         temp.push_back(root->val);
        //         temp.push_back(root->right->val);
        //         ans.push_back(temp);
        //     }
        //     return ans;
        // }
        
        
        int ct=0;
        
        check(root,ct,targetSum,temp,ans);
        
        return ans;
        
    }
};