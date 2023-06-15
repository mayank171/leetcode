
class BSTIterator {
public:
    
    stack<TreeNode*> stk;
    TreeNode* root;
    
    BSTIterator(TreeNode* root) {
        this->root=root;
        
        while(this->root->left)
        {
            stk.push(this->root);
            this->root=this->root->left;
        }
        stk.push(this->root);
    }
    
    int next() {
        
        TreeNode* x=stk.top();
        stk.pop();
        
        int ans=x->val;
        
        if(x->right!=NULL)
        {
            x=x->right;
            
            while(x->left)
            {
                stk.push(x);
                x=x->left;
                
            }
            stk.push(x);
        }
        
      //  cout<<ans<<endl;
        
        return ans;
    }
    
    bool hasNext() {
        
        if(stk.empty())
            return false;
        return true;
    }
};
