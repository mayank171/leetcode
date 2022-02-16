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
     void check(TreeNode* root,map<int,vector<int>> &mp)
     {
         queue<pair<TreeNode*,int>> q;
         q.push({root,0});
         
         while(!q.empty())
         {
             TreeNode* x=q.front().first;
             int lev=q.front().second;
             q.pop();
             
             mp[lev].push_back(x->val);
             
             if(x->left!=NULL)
                q.push({x->left,lev+1});
             if(x->right!=NULL)
                q.push({x->right,lev+1});
         }
     }
public:
    vector<int> rightSideView(TreeNode* root) {
 
      
      vector<int> ans;
      
      if(root==NULL)
          return ans;
        
      map<int,vector<int>> mp;
      
      check(root,mp);
      
      for(auto &it:mp)
      {
          vector<int> &v=it.second;
          ans.push_back(v[v.size()-1]);
      }
      
      return ans;
      
    }
};