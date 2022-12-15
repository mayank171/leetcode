//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* solve(int *in,int *pre,int &ind,map<int,int> &mp,int left,int right,int n)
    {
      //  cout<<left<<" "<<right<<" "<<ind<<endl;
        
        
        if(left>right)
           return NULL;
        
       
        
        Node* node=new Node(pre[ind]);
        int x=ind;
        ind+=1;
        node->left=solve(in,pre,ind,mp,left,mp[pre[x]]-1,n);
        
        node->right=solve(in,pre,ind,mp,mp[pre[x]]+1,right,n);
        
        return node;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        
        int ind=0;
        Node* root= solve(in,pre,ind,mp,0,n-1,n);
        
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends