/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string str1="";
    string str2="";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL)
            return "N";
        
        string num=to_string(root->val);
        string str=num;
        
        string l=serialize(root->left);
        string r=serialize(root->right);
        
        string str1=str+"L"+l+"R"+r;
        
        return str1;
    }
    
    TreeNode* solve(string &data,int n,int &ind)
    {
        if(ind==n)
            return NULL;
        
        if(data[ind]=='N')
        {
            ind++;
            return NULL;
        }
        
        int k=0;
        int j=ind;
        while(ind<n && data[j]>='0' && data[j]<='9')
        {
            k=k*10+(data[j]-'0');
            j++;
        }
        
        ind=j;
        TreeNode* node=new TreeNode(k);
        
        if(data[ind]=='L')
        {
            ind++;
            node->left=solve(data,n,ind);
        }
        
        if(data[ind]=='R')
        {
            ind++;
            node->right=solve(data,n,ind);
        }
        
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    
        int n=data.size();
        
        int ind=0;
        
        return solve(data,n,ind);
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;