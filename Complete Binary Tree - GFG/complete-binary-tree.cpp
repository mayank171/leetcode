//{ Driver Code Starts
// A program to check if a given binary tree is complete or not
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));
        
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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
    

class Solution{
public:    
    bool isCompleteBT(Node* root){
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        int k=1;
        int flag=0;
        
        vector<int> vis(500,-1);
        vis[0]=root->data;
        
        while(!q.empty())
        {
            int size=q.size();
            
            if(k>size && flag==0)
            {
                flag=1;
            }
            else if(k>size && flag==1)
                return 0;
                
            for(int i=0;i<size;i++)
            {
                Node* node=q.front().first;
                int ind=q.front().second;
                q.pop();
                
                int left=0;
                int right=0;
                
                if(node->left)
                {
                    vis[2*ind+1]=node->left->data;
                    q.push({node->left,2*ind+1});
                }
                else
                   left=1;
                   
                if(node->right)
                {
                    vis[2*ind+2]=node->right->data;
                    q.push({node->right,2*ind+2});
                }
                else
                   right=1;
                   
                if(left==1 && right==0)
                {
                    return 0;
                }
            }
            
            k*=2;
        }
        
        // for(int i=0;i<10;i++)
        //   cout<<vis[i]<<" ";
        // cout<<endl;
        
        for(int i=0;i<vis.size()-1;i++)
        {
            if(vis[i]==-1 && vis[i+1]!=-1)
               return 0;
        }
        
        return 1;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		Solution ob;
        if(ob.isCompleteBT(root)){
            printf ("Complete Binary Tree\n");
        }
        else{
            printf ("Not Complete Binary Tree\n");
        } 
    }
    return 0;
}





// } Driver Code Ends