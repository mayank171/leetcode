//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

Node* solve(int *in,int *post,int &ind,map<int,int> &mp,int left,int right)
{
    if(left>right)
       return NULL;
       
    Node* node=new Node(post[ind]);
    int x=ind;
    ind--;
    node->right=solve(in,post,ind,mp,mp[post[x]]+1,right);
    
    node->left=solve(in,post,ind,mp,left,mp[post[x]]-1);
    
    return node;
}


Node *buildTree(int in[], int post[], int n) {
    
    map<int,int> mp;
    
    for(int i=0;i<n;i++)
    {
        mp[in[i]]=i;
    }
    
   // reverse(post,post+n);
    int ind=n-1;
    Node* root=solve(in,post,ind,mp,0,n-1);
    
    return root;
    
}
