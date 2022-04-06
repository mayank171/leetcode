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
class FindElements {
private:
    unordered_set<int> s;
    TreeNode* node;
public:
   
    
    FindElements(TreeNode* root) {
        node=root;
        root->val=0;
        s.insert(0);
    
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            {
                node->left->val=2*node->val+1;
                s.insert(node->left->val);
                q.push(node->left);
            }
            
            if(node->right!=NULL)
            {
                node->right->val=2*node->val+2;
                s.insert(node->right->val);
                q.push(node->right);
                
            }
        }
    }
    
    bool find(int target) {
        
        return s.find(target)!=s.end()?true:false;
        
//         queue<TreeNode*> q;
            
//         q.push(node);
        
        
//         while(!q.empty())
//         {
//             TreeNode* node1=q.front();
//             if(node1->val==target)
//                 return true;
            
//             q.pop();
            
//             if(node1->left)
//             {
//                 q.push(node1->left);
//             }
            
//             if(node1->right)
//             {
//                 q.push(node1->right);
                
//             }
//         }
        
//         return false;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */