//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    bool solve(Node* node,int level)
    {
        if(node==NULL)
        {
           // st.insert(level);
            return true;
        }
        
        if(node->left==NULL && node->right!=NULL)
           return false;
           
        bool l=solve(node->left,level+1);
        bool r=solve(node->right,level+1);
        
        
        if(l==false || r==false)
           return false;
           
        int flag=0;
        if(node->left && node->left->data>node->data)
           flag=1;
        if(node->right && node->right->data>node->data)
           flag=1;
        
        if(flag==1)
           return false;
           
        return true;
    }
    
    int height(Node* node,int &flag)
    {
        if(node==NULL)
            return 0;
            
        int l=height(node->left,flag);
        int r=height(node->right,flag);
        
        if(abs(l-r)>1)
           flag=1;
        
        return 1+max(l,r);
    }
  
    bool isHeap(struct Node* tree) {
        // code here
        set<int> st;
        int flag=0;
        int h=height(tree,flag);
       // cout<<h<<endl;
       
        if(flag==1)
           return false;
        
        queue<Node*> q;
        q.push(tree);
        
        while(!q.empty())
        {
            int size=q.size();
            
            int flag=0;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                
                if(node->left==NULL && node->right)
                {
                    return 0;
                }
                
                if(flag==0 && node->left)
                {
                    q.push(node->left);
                }
                else if(flag==1 && node->left)
                    return 0;
                
                if(flag==0 && node->right)
                {
                    q.push(node->right);
                }
                else if(flag==1 && node->right)
                    return 0;
                
                if(node->left==NULL && node->right==NULL)
                {
                    flag=1;
                }
            }
        }
        
        return solve(tree,0);
    }
};





















//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends