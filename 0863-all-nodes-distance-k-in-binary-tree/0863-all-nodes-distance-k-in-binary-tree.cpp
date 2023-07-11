/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void markparent(TreeNode* root,map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right)
            {
                q.push(node->right);
                parent[node->right]=node;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(k==0)
        {
            return {target->val};
        }
        
        map<TreeNode*,TreeNode*> markParent;
        
        markparent(root,markParent);
        
        queue<TreeNode*> q;
        q.push(target);
        
        // for(auto &it:markParent)
        // {
        //     cout<<it.first->val<<" "<<it.second->val<<endl;
        // }
        
        map<TreeNode*,bool> vis;
        vis[target]=true;
        
        while(!q.empty())
        {
            int size=q.size();
            k--;
            
            
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left && vis.find(node->left)==vis.end())
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && vis.find(node->right)==vis.end())
                {
                    q.push(node->right);
                    vis[node->right]=true;
                }
                
                if(markParent.find(node)!=markParent.end() && vis.find(markParent[node])==vis.end())
                {
                    q.push(markParent[node]);
                    vis[markParent[node]]=true;
                }
            }
            
            
            if(k==0)
                break;
        }
        
        vector<int> ans;
        
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        
        return ans;
    }
};













