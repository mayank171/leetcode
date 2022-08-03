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
//     int check(TreeNode* root,int &maxi)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         }
        
//         int l=max(0,check(root->left,maxi));
//         int r=max(0,check(root->right,maxi));

//         maxi=max(l+r+root->val,maxi);
 
//         return root->val+max(l,r);
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//     int check(TreeNode* root,int &ans)
//     {
//         if(root==NULL)
//             return 0;
        
//         int l=check(root->left,ans);
//         int r=check(root->right,ans);
        
//         if(l<0)
//             l=0;
        
//         if(r<0)
//             r=0;
        
//         ans=max(ans,l+r+root->val);
        
//         return max(l,r)+root->val;
        
//     }
    
    
    
    
    
    
    
    int check(TreeNode* root,int &ans)
    {
        if(root==NULL)
           return 0;
           
        int l=check(root->left,ans);
        int r=check(root->right,ans);
        
        int temp=max(max(l,r)+root->val,root->val);
        
        int temp1=max(temp,l+r+root->val);
        
        ans=max(ans,temp1);
        
        return temp;
    }
    
    
    
    
    
    
    
    
    
    
    
public:
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
//         if(root->left==NULL && root->right!=NULL)
//         {
//             if(root->val>0 && root->right->val>0)
//                 return root->val+root->right->val;
//             else
//                 retur
//         }
            
        
//         int maxi=INT_MIN;
//         check(root,maxi);
        
//         return maxi;
        
         int ans=-1e8;
        check(root,ans);
        
        return ans;
    }
};