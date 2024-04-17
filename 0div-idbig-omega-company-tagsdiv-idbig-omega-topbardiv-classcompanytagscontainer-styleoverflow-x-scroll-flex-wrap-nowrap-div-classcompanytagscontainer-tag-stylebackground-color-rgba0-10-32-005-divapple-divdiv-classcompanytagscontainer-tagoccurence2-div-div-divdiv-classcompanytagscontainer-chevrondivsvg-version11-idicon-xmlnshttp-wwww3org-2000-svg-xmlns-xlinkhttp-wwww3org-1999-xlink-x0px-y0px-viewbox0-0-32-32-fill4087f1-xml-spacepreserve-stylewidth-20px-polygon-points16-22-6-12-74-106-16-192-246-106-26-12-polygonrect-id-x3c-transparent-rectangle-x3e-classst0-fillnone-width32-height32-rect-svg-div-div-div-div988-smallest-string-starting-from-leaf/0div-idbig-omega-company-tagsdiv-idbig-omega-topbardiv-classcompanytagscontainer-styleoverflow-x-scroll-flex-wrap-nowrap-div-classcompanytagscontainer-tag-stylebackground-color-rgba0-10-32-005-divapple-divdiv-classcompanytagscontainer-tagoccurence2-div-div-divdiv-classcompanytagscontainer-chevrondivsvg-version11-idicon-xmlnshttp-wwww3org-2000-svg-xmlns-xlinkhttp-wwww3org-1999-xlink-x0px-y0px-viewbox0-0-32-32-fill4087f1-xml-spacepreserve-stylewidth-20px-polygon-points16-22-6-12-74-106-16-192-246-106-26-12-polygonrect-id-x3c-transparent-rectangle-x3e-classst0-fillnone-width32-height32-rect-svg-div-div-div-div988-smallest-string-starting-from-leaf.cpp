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
    
    void solve(TreeNode* root,set<string> &st,string &str)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            str+=(root->val+'a');
                string s=str;
                reverse(s.begin(),s.end());
                st.insert(s);    
            str.pop_back();
            return ;
        }
        
        str+=(root->val+'a');
        solve(root->left,st,str);
        solve(root->right,st,str);
        str.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        set<string> st;
    
        string str="";
        solve(root,st,str);
        
        if(st.size()==0)
        {
            char ch=(root->val+'a');
            string ans="";
            ans+=ch;
            return ans;
        }
        
        //for(auto &it:st)
          //  cout<<it<<endl;
            
        return *st.begin();
    }
};