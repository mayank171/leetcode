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
private:
    void check(TreeNode* root,vector<int> inorder,vector<int> postorder)
    {
        root->val=postorder[postorder.size()-1];
        
        vector<int> in;
        vector<int> po;
        
        int ind=0;
        int size=inorder.size();
        for(int i=0;i<size;i++)
        {
            if(inorder[i]==postorder[postorder.size()-1])
            {
               ind=i;
               break;   
            }
        }
        
        for(int i=0;i<ind;i++)
        {
            in.push_back(inorder[i]);
        }
        
        int ctr=in.size();
        int size1=postorder.size();
        int ind1=1;
        int ind2=1;
        if(ctr>0)
        {
            for(int i=0;i<size1;i++)
            {
                if(ctr==0)
                {
                    ind2=i;
                    break;
                }
                else
                {
                    po.push_back(postorder[i]);
                    //postorder[i]=-3001;
                    ctr--;
                }
            }
        }
        
        vector<int> in1;
        vector<int> po1;
        
        for(int i=ind+1;i<size;i++)
        {
            in1.push_back(inorder[i]);
        }
        
        int ctr1=in1.size();
        for(int i=in.size();i<size1;i++)
        {
            if(ctr1==0)
                break;
            if(postorder[i]!=-3001)
            {
                po1.push_back(postorder[i]);
                ctr1--;
            }
        }
        
         if(in.size()!=0)
        {
            TreeNode* left=new TreeNode();
            root->left=left;
            left->val=321123;
            check(left,in,po);
        }
            
        else
            root->left=NULL;
        
        if(in1.size()!=0)
        {
            TreeNode* right=new TreeNode();
            root->right=right;
            right->val=321123;
            check(right,in1,po1);
        }    
        else
            root->right=NULL;
        
        
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        TreeNode* root=new TreeNode();
        
        check(root,inorder,postorder);
        
        return root;
        
    }
};