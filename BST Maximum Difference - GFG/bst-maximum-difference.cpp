//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void search(Node* root,int target,Node* &node,int &dist)
    {
        if(root==NULL)
           return ;
        
        if(root->data==target)
        {
            node=root;
            return ;
        }
        
        dist+=root->data;
        
        if(root->data>target)
        {
           search(root->left,target,node,dist); 
        }
        else
        {
           search(root->right,target,node,dist); 
        }
    }
    
    
    int solve(Node* node)
    {
        if(node==NULL)
           return 1e9;
        
        if(node->left==NULL && node->right==NULL)
           return node->data;
           
        int x=node->data+solve(node->left);
        int y=node->data+solve(node->right);
        
        return min(x,y);
    }
    

    int maxDifferenceBST(Node *root,int target){
        
        Node* node=NULL;
        int dist=0;
        
        search(root,target,node,dist);
        
        
        
        if(node==NULL)
           return -1;
           
      //  cout<<dist<<endl;
           
        int dist2=solve(node);
        dist2-=node->data;
        
      //  cout<<dist2<<endl;
        
        return dist-dist2;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends