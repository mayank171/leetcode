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
        
        
        if(target==0)
            return true;
        
        int x=target+1;
        
        int digits=floor(log10(x));
        
        for(int i=digits;i>=0;i--)
        {
            int val=x&(1<<i);
            
            if(val==0)
            {
                if(node->left)
                {
                    node=node->left;
//                     if(root->val==target)
//                         return true;
                    
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(node->right)
                {
                    node=node->right;
                    // if(root->val==target)
                    //     return true;
                }
                else
                {
                    return false;
                }
            }
        }
        
        if(node->val==target)
            return true;
        
        return false;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */