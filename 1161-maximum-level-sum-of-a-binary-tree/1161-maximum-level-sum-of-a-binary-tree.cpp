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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int maxi=-1e9;
        int ind=-1;
        int i=0;
        
        while(!q.empty())
        {
            int size=q.size();
            i++;
            int sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                sum+=node->val;
            }
            
            if(sum>maxi)
            {
                maxi=sum;
                ind=i;
            }
        }
        
        return ind;
        
    }
};