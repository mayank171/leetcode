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
    void check(TreeNode* root, vector<int> preorder, vector<int> inorder)
    {
        if(root==NULL)
        {
            for(auto &it:inorder)
            {
                cout<<it<<" ";
            }
            cout<<endl;
            for(auto &it:preorder)
            {
                cout<<it<<" ";
            }
            cout<<endl;
            
            cout<<"vmdv"<<endl;
            return ;
        }
            
      
        root->val=preorder[0];
       
        int ind=0;
        int size=inorder.size();
        for(int i=0;i<size;i++)
        {
            if(inorder[i]==preorder[0])
            {
               ind=i;
               break;   
            }
        }
        
        vector<int> in;
        vector<int> pre;
        
        for(int i=0;i<ind;i++)
        {
            in.push_back(inorder[i]);
        }
      
        
        int ctr=in.size();
        int size1=preorder.size();
        int ind1=1;
        int ind2=1;
        if(ctr>0)
        {
            for(int i=ind1;i<size1;i++)
            {
                if(ctr==0)
                {
                    ind2=i;
                    break;
                }
                else
                {
                    pre.push_back(preorder[i]);
                    ctr--;
                }
            }
        }
        
        vector<int> in1;
        vector<int> pre1;
        
        for(int i=ind+1;i<size;i++)
        {
            in1.push_back(inorder[i]);
        }
        
        int ctr1=in1.size();
        for(int i=ind2;i<size1;i++)
        {
            if(ctr1==0)
                break;
            if(preorder[i]!=-3001)
            {
                pre1.push_back(preorder[i]);
                ctr1--;
            }
        }
        
//         cout<<"in"<<endl;
//         for(auto &it:in)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         cout<<"pre"<<endl;
//         for(auto &it:pre)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         cout<<"in1"<<endl;
//         for(auto &it:in1)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         cout<<"pre1"<<endl;
//         for(auto &it:pre1)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        
        if(in.size()!=0)
        {
            TreeNode* left=new TreeNode();
            root->left=left;
            left->val=321123;
            check(left,pre,in);
        }
            
        else
            root->left=NULL;
        
        if(in1.size()!=0)
        {
            TreeNode* right=new TreeNode();
            root->right=right;
            right->val=321123;
            check(right,pre1,in1);
        }    
        else
            root->right=NULL;
        
        
        
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* root=new TreeNode();
//         root->left=NULL;
//         root->right=NULL;
        
        
        check(root,preorder,inorder);
        
        return root;
    }
};