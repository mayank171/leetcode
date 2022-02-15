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
    void inorder(TreeNode* root,map<int,map<int,multiset<int>>> &mp,int lev,int vert)
    {
        if(root==NULL)
            return ;
        
        inorder(root->left,mp,lev+1,vert-1);
        mp[vert][lev].insert(root->val);
        inorder(root->right,mp,lev+1,vert+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> mp;
        
        int level=0;
        int vert=0;
        
        inorder(root,mp,level,vert);
        
        vector<vector<int>> ans;
        
        for(auto &lev:mp)
        {
            vector<int> temp;
            for(auto &it1:lev.second)
            {
                for(auto &it2:it1.second)
                {
                    temp.push_back(it2);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};