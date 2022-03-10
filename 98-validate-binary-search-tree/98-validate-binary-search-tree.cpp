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
    // void check(TreeNode* root,int last,int dir,bool &flag)
//     {
//         if(root==NULL)
//             return ;
        
//         if(dir==-1)
//         {
//             if(root->val>last)
//             {
//                 flag=false;
//                 return ;
//             }
                
//         }
        
//         if(dir==1)
//         {
//             if(root->val<last)
//             {
//                 flag=false;
//                 return ;
//             }
//         }
        
//         check(root->left,root->val,-1,flag);
             
        
        
//         check(root->right,root->val,1,flag);
              
        
//     }
        
    void check(TreeNode* root,long &inorder,int &flag)
    {
        if(root==NULL)
            return ;
        
        check(root->left,inorder,flag);
        if(inorder>=root->val)
        {
            flag=0;
            return ;
        } 
        else
            inorder=root->val;
        check(root->right,inorder,flag);
    }
public:
    bool isValidBST(TreeNode* root) {
        
//         bool flag=true;
        
//         check(root,-1,0,flag);
        
//         return flag;
        
        // vector<int> inorder;
        
        long inorder=LONG_MIN;
        int flag=1;
        
        check(root,inorder,flag);
        
        if(flag==1)
            return true;
        else
            return false;
        
//         for(int i=1;i<inorder.size();i++)
//         {
//            // cout<<inorder[i]<<" ";
//             if(inorder[i]<=inorder[i-1])
//                 return false;
//         }
        
//         return true;
        
    }
};