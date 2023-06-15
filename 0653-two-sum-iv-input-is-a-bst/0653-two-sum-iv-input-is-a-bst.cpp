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
    
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    TreeNode* root1;
    TreeNode* root2;
    
    void initialize(TreeNode* root)
    {
        TreeNode* temp=root;
        
        while(temp->left)
        {
            stk1.push(temp);
            temp=temp->left;
        }
        stk1.push(temp);
        
        temp=root;
        while(temp->right)
        {
            stk2.push(temp);
            temp=temp->right;
        }
        stk2.push(temp);
        
    }
    
    bool solve(int k)
    {
        
        while(!stk1.empty() || !stk2.empty())
        {
            
            TreeNode* node1=stk1.top();
            TreeNode* node2=stk2.top();
            
            if(node1==node2)
                break;
           
            cout<<node1->val<<" "<<node2->val<<endl;
        
            if(node1->val+node2->val==k)
                return true;
            else if(node1->val+node2->val>k)
            {
                stk2.pop();
                if(node2->left)
                {
                    node2=node2->left;
                    while(node2->right)
                    {
                        stk2.push(node2);
                        node2=node2->right;
                    }
                    stk2.push(node2);
                }
            }
            else
            {
                stk1.pop();
                if(node1->right)
                {
                    node1=node1->right;
                    while(node1->left)
                    {
                        stk1.push(node1);
                        node1=node1->left;
                    }
                    stk1.push(node1);
                }
            }
        }
        
        return false;
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        if(root->left==NULL && root->right==NULL)
        {
            return false;
        }
        
        initialize(root);
        
        return solve(k);
        
    }
};










