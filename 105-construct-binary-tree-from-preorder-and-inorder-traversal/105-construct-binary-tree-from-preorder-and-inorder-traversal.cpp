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
//     void check(TreeNode* root, vector<int> preorder, vector<int> inorder)
//     {
//         if(root==NULL)
//         {
           
//             return ;
//         }
            
      
//         root->val=preorder[0];
       
//         int ind=0;
//         int size=inorder.size();
//         for(int i=0;i<size;i++)
//         {
//             if(inorder[i]==preorder[0])
//             {
//                ind=i;
//                break;   
//             }
//         }
        
//         vector<int> in;
//         vector<int> pre;
        
//         for(int i=0;i<ind;i++)
//         {
//             in.push_back(inorder[i]);
//         }
      
        
//         int ctr=in.size();
//         int size1=preorder.size();
//         int ind1=1;
//         int ind2=1;
//         if(ctr>0)
//         {
//             for(int i=ind1;i<size1;i++)
//             {
//                 if(ctr==0)
//                 {
//                     ind2=i;
//                     break;
//                 }
//                 else
//                 {
//                     pre.push_back(preorder[i]);
//                     ctr--;
//                 }
//             }
//         }
        
//         vector<int> in1;
//         vector<int> pre1;
        
//         for(int i=ind+1;i<size;i++)
//         {
//             in1.push_back(inorder[i]);
//         }
        
//         int ctr1=in1.size();
//         for(int i=ind2;i<size1;i++)
//         {
//             if(ctr1==0)
//                 break;
//             if(preorder[i]!=-3001)
//             {
//                 pre1.push_back(preorder[i]);
//                 ctr1--;
//             }
//         }
  
        
//         if(in.size()!=0)
//         {
//             TreeNode* left=new TreeNode();
//             root->left=left;
//             left->val=321123;
//             check(left,pre,in);
//         }
            
//         else
//             root->left=NULL;
        
//         if(in1.size()!=0)
//         {
//             TreeNode* right=new TreeNode();
//             root->right=right;
//             right->val=321123;
//             check(right,pre1,in1);
//         }    
//         else
//             root->right=NULL;
        
        
        
//     }
//     TreeNode* usingMap(vector<int> &preorder,vector<int> &inorder,int &ind,int left,int right,unordered_map<int,int> &mp)
//     {
//         if(left>right)
//             return NULL;
        
//         int pivot=mp[preorder[ind]];
        
//         TreeNode* node=new TreeNode();
//         node->val=inorder[pivot];
//         ind++;
        
//         node->left=usingMap(preorder,inorder,ind,left,pivot-1,mp);
//         node->right=usingMap(preorder,inorder,ind,pivot+1,right,mp);
//         return node;
//     }
    
    
    
    TreeNode* check(vector<int> &preorder,vector<int> &inorder,unordered_map<int,int> &mp,int &ind,int left,int right)
    {
        if(left>right)
            return NULL;
        
        int pivot=mp[preorder[ind]];
        TreeNode* node=new TreeNode();
        node->val=inorder[pivot];
        ind++;
        
        node->left=check(preorder,inorder,mp,ind,left,pivot-1);
        node->right=check(preorder,inorder,mp,ind,pivot+1,right);
        return node;
    }
    
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        
        int n=preorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        int ind=0;
        // TreeNode* root=
        return 
        check(preorder,inorder,mp,ind,0,n-1);
        
      //  return root;
        
        
        
        
//         unordered_map<int,int> mp;
//         int ind=0;
//         int size=preorder.size();
        
        
//         for(int i=0;i<size;i++)
//         {
//             mp[inorder[i]]=i;
//         }
        
//         TreeNode* root=usingMap(preorder,inorder,ind,0,size-1,mp);
//         return root;
    }
};