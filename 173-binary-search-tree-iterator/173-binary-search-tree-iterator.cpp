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
class BSTIterator {
private:
    int ans=-1;
    TreeNode* root1;
    stack<TreeNode*> stk;
    
    void push(TreeNode* node)
    {
        while(node!=NULL)
        {
            stk.push(node);
            node=node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        // TreeNode* temp=root1;
        // int a=-1;
        // while(temp!=NULL)
        // {
        //     if(temp->val>ans)
        //     {
        //         a=temp->val;
        //         temp=temp->left;
        //     }
        //     else
        //     {
        //         temp=temp->right;
        //     }
        // }
        // ans=a;
        // return a;
        
        TreeNode* temp=stk.top();
        stk.pop();
        int ans=temp->val;
        
        if(temp->right!=NULL)
        {
            push(temp->right);
        }
        return ans;
    }
    
    bool hasNext() {
//         TreeNode* temp=root1;
//         int s=-1;
//         while(temp!=NULL)
//         {
//             s=temp->val;
//             temp=temp->right;
//         }
        
//         if(s==ans)
//             return false;
//         else
//             return true;
        
        if(stk.empty())
            return false;
        else
            return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */