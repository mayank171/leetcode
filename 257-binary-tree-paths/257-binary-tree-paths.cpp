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
    void check(TreeNode* root,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(root==NULL)
        {
            return ;
        }
    
        temp.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(temp);
            temp.pop_back();
            return ;
        }
        
        check(root->left,temp,ans);
        check(root->right,temp,ans);
        temp.pop_back();
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        check(root,temp,ans);
        
        vector<string> sans;
        
        for(int i=0;i<ans.size();i++)
        {
            string s="";
            for(int j=0;j<ans[i].size();j++)
            {
                s+=to_string(ans[i][j]);
                if(j!=ans[i].size()-1)
                    s+="->";
            }
            sans.push_back(s);
            cout<<endl;
        }
        
        
        
        return sans;
    }
};