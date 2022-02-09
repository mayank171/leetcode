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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        int flag=1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int> temp;
            stack<int> stk;
            queue<int> q1;
        
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(flag==-1)
                {
                    if(node->left!=NULL)
                    {
                        q.push(node->left);
                    }
                    if(node->right!=NULL)
                    {
                        q.push(node->right);
                    }
                    stk.push(node->val);
                }
                else
                {
                    if(node->left!=NULL)
                    {
                        q.push(node->left);
                    }
                    if(node->right!=NULL)
                    {
                        q.push(node->right);
                    }
                    q1.push(node->val);
                }
            }
            if(flag==-1)
            {
                while(!stk.empty())
                {
                    int x=stk.top();
                    stk.pop();
                    temp.push_back(x);
                }
            }
            else
            {
                while(!q1.empty())
                {
                    int x=q1.front();
                    q1.pop();
                    temp.push_back(x);
                }
            }
            flag*=-1;
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};