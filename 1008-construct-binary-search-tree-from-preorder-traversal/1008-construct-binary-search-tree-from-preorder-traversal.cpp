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
//     TreeNode* check(vector<int> &preorder,vector<int> &inorder,unordered_map<int,int> &mp,int &ind,int left,int right)
//     {
//         if(left>right)
//             return NULL;
        
//         TreeNode* node=new TreeNode();
//         int pivot=mp[preorder[ind]];
//         node->val=inorder[pivot];
//         ind++;
        
//         node->left=check(preorder,inorder,mp,ind,left,pivot-1);
//         node->right=check(preorder,inorder,mp,ind,pivot+1,right);
//         return node;
//     }
public:
    
    TreeNode* check(vector<int> &preorder,int &ind,int maxi)
    {
        if(ind==preorder.size())
            return NULL;
        
        if(preorder[ind]>maxi)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[ind++]);
        root->left=check(preorder,ind,root->val);
        root->right=check(preorder,ind,maxi);
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        
        int ind=0;
        return check(preorder,ind,1e8);
        
//         vector<int> inorder=preorder;
//         sort(inorder.begin(),inorder.end());
        
//         unordered_map<int,int> mp;
        
//         for(int i=0;i<inorder.size();i++)
//         {
//             mp[inorder[i]]=i;
//         }
        
//         //TreeNode* root=new TreeNode();
        
//         int ind=0;
        
//         TreeNode* root=check(preorder,inorder,mp,ind,0,preorder.size()-1);
        
//         return root;
        
    }
};