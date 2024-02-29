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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int k=0;
        
        while(!q.empty())
        {
            int size=q.size();
            
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                if((k%2==0 && node->val%2==0)||(k%2!=0 && node->val%2!=0))
                    return false;
                
                temp.push_back(node->val);
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            cout<<endl;
            
            if(temp.size()==1)
            {
                k++;
                continue;
            }
            
            if(k%2==0)
            {
                
                for(int i=1;i<temp.size();i++)
                {
                    if(temp[i]<=temp[i-1])
                        return false;
                }
            }
            else
            {
                for(int i=1;i<temp.size();i++)
                {
                    if(temp[i]>=temp[i-1])
                        return false;
                }    
            }
            k++;
        }
        
        return true;
    }
};