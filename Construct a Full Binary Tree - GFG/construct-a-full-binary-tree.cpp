//{ Driver Code Starts
//Initial Template for C++
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


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    int ind=0;
    int t=0;
    Node* solve(int *pre,int *preMirror,int size,set<int> &st,map<int,int> &mp)
    {
    
        if(ind>=size)
          return NULL;
          
        Node* node=new Node(pre[ind]);
    //    node->data=pre[ind];
        node->left=NULL;
        node->right=NULL;
        
        int left=-1;
        int right=-1;
        
        if(t==1)
          return NULL;
        
        if(ind+1<size)
           left=pre[ind+1];
           
           
        // cout<<left<<endl;
        // if(t==1)
        //   return NULL;
          
        if(mp[pre[ind]]+1<size)
           right=preMirror[mp[pre[ind]]+1];
           
        // cout<<left<<" "<<right<<endl;
        // t++;
        
        // if(t==2)
        //   return NULL;
        
        
        if(left==-1 || right==-1)
        {
            return node;
        }
        
        if(st.find(left)!=st.end() || st.find(right)!=st.end())
        {
            return node;
        }
        
        
        st.insert(left);
        st.insert(right);
        
        if(left==right)
        {
            ind++;
            node->left=solve(pre,preMirror,size,st,mp);
        }
        else
        {
            ind++;
           // cout<<ind<<endl;
            node->left=solve(pre,preMirror,size,st,mp);
    
        
            ind++;
            node->right=solve(pre,preMirror,size,st,mp);
        }
        
        return node;
    }
  
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        set<int> st;
        map<int,int> mp;
        for(int i=0;i<size;i++)
        {
            mp[preMirror[i]]=i;
        }
        
        st.insert(pre[0]);
        return solve(pre,preMirror,size,st,mp);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends