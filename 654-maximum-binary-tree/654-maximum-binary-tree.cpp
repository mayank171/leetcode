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
// private:
//     void heapify(vector<int> &nums,int i,int size)
//     {
//         int l=i;
//         int lft=2*i+1;
//         int rgt=2*i+2;
        
//         if(lft<size && nums[lft]>nums[l])
//             l=lft;
//         if(rgt<size && nums[rgt]>nums[l])
//             l=rgt;
        
//         if(l!=i)
//         {
//             swap(nums[i],nums[l]);
//             heapify(nums,l,size);
//         }
        
//     }
    TreeNode* check(TreeNode* root,vector<int> nums,int size)
    {
    
        if(size==0)
        {
            root=NULL;
            return root;
        }
        int max=INT_MIN;
        int ind=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
                ind=i;
            }
        }
        
        TreeNode* x=new TreeNode();
        x->val=nums[ind];
        root=x;
        
        vector<int> left;
        vector<int> right;
        
        for(int i=0;i<ind;i++)
        {
            left.push_back(nums[i]);
        }
        
        for(int i=ind+1;i<size;i++)
        {
            right.push_back(nums[i]);
        }
        
        
        //TreeNode* x1=check(root->left,left,left.size());
        
        root->left=check(root->left,left,left.size());
        
//         if(x1)
//         {
//             root->left=x1;
//         }
//         else
//         {
//             root->left=NULL;
//         }
        
        //TreeNode* y=check(root->right,right,right.size());
        
//         if(y)
//         {
//             root->right=y;
//         }
//         else
//         {
//             root->right=NULL;
//         }
        
        root->right=check(root->right,right,right.size());
        
        return root;
        
        
        
        
    }
    
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        TreeNode* root=new TreeNode();

        int size=nums.size();
        TreeNode* x=check(root,nums,size);
        
        return x;
    }
};