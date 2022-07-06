// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector<int> diagonal(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
void check(Node* root,vector<int> adj[],int level)
{
    if(root==NULL)
      return ;
   // cout<<level<<" "<<root->data<<endl;
    adj[level].push_back(root->data);
    check(root->left,adj,level+1);
    check(root->right,adj,level);
    
}

void countLeft(Node* root,int &ctLevel,int cur)
{
    if(root==NULL)
    {
        ctLevel=max(ctLevel,cur);
        return;
    }
    countLeft(root->left,ctLevel,cur+1);
    countLeft(root->left,ctLevel,cur);
    
}

vector<int> diagonal(Node *root)
{
   // your code here
   int ct_level=0;int cur=0;
   Node* temp=root;
   
   countLeft(temp,ct_level,cur);
  // cout<<ct_level<<endl;
  // cout<<ct_level<<endl;
   
   vector<int> adj[ct_level+100];
   
   check(root,adj,0);
  
   vector<int> ans;
   
   for(int i=0;i<ct_level+100;i++)
   {
       for(int j=0;j<adj[i].size();j++)
       {
           ans.push_back(adj[i][j]);
       }
   }
   
   return ans;
   
}