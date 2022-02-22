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
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left)
            {
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                mp[node->right]=node;
                q.push(node->right);
            }
            
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> mp;
        markParent(root,mp);
        
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        queue<TreeNode*> q;
        q.push(target);
        int dis=0;
        
        while(!q.empty())
        {
            int size=q.size();
            
            if(dis==k)
                break;
            dis++;
            
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left && !vis[node->left])
                {
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right])
                {
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(mp[node] && !vis[mp[node]])
                {
                    vis[mp[node]]=true;
                    q.push(mp[node]);
                }
                
            }
        }
        
        vector<int> ans;
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
        
    }
};