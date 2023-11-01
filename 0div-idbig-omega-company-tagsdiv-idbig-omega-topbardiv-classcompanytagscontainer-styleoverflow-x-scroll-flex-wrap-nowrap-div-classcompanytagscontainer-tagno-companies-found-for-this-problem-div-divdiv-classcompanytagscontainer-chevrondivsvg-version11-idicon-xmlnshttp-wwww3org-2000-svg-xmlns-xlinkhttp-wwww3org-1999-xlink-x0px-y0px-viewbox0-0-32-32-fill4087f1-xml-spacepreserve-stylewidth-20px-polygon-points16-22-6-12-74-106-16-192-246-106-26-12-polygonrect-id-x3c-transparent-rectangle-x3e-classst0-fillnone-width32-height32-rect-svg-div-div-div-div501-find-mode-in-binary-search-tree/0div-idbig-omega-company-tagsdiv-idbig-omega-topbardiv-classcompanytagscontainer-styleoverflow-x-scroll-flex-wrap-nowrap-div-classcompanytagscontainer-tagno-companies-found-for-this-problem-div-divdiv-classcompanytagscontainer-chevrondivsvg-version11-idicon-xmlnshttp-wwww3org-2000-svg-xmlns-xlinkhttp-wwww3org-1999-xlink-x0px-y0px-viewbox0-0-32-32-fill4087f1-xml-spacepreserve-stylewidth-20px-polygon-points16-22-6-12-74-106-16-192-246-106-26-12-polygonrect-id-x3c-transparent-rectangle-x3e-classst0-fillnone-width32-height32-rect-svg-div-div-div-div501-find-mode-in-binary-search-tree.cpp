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
    
    void solve(TreeNode* root,int &ct,int &maxi,int &val)
    {
        
        if(root==NULL)
            return ;
        
        solve(root->left,ct,maxi,val);
        
        if(root->val==val)
        {
            ct++;
            maxi=max(maxi,ct);
        }
        else
        {
            if(ct>maxi)
            {
                maxi=ct;
            }
            val=root->val;
            ct=1;        
        }
        
        solve(root->right,ct,maxi,val);
//        cout<<maxi<<" "<<val<<endl;
    }
    
    void solve1(TreeNode* root,int &maxi,vector<int> &ans,int &ct,int &val)
    {
        
        if(root==NULL)
            return ;
        
        solve1(root->left,maxi,ans,ct,val);
        
        if(root->val==val)
        {
            ct++;
            
        }
        else
        {
            if(ct==maxi)
            {
                ans.push_back(val);
            }
            val=root->val;
            ct=1;        
        }
        
        solve1(root->right,maxi,ans,ct,val);
//        cout<<maxi<<" "<<val<<endl;
    }
    
    vector<int> findMode(TreeNode* root) {
        
        if(root->left==NULL && root->right==NULL){
            return {root->val};
        }
        
        int ct=0;
        int maxi=0;
        int val=-1e6;
        
        solve(root,ct,maxi,val);
        cout<<maxi<<endl;
        
        vector<int> ans;
        ct=0;
        val=-1e6;
        
        solve1(root,maxi,ans,ct,val);
        
        if(ct==maxi)
        {
            ans.push_back(val);
        }
        
        return ans;
    }
};