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
   
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans =0;
        
        while(!q.empty())
        {
            int size=q.size();
            int min=q.front().second;
            int maxi=q.back().second;
            int first,last;
            
            for(int i=0;i<size;i++)
            {
                int cur_ind=q.front().second-maxi;
                TreeNode* node=q.front().first;
                q.pop();
                
                if(i==0)
                    first=cur_ind;
                if(i==size-1)
                    last=cur_ind;
                
                if(node->left!=NULL)
                    q.push({node->left,2*cur_ind+1});
                if(node->right!=NULL)
                    q.push({node->right,2*cur_ind+2});
            }
            ans=max(ans,last-first+1);
        }
        
        return ans;
    }
};