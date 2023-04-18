//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    struct bst
    {
        int isBst;
        int len;
        int sum;
        int maxi;
        int mini;
    };


    struct bst* solve(Node* root,int target,int &mini)
    {
        if(root==NULL)
        {
            struct bst* temp=new bst();
            temp->isBst=true;
            temp->len=0;
            temp->sum=0;
            temp->maxi=-1e9;
            temp->mini=1e9;
            return temp;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            if(root->data==target)
            {
                struct bst* temp=new bst();
                temp->isBst=true;
                temp->len=1;
                temp->sum=root->data;
                temp->maxi=root->data;
                temp->mini=root->data;
                mini=min(mini,temp->len);
               // cout<<temp->isBst<<" "<<temp->len<<" "<<temp->sum<<" "<<temp->maxi<<" "<<temp->mini<<endl;
                
                return temp;    
            }
            struct bst* temp=new bst();
            temp->isBst=true;
            temp->len=1;
            temp->sum=root->data;
            temp->maxi=root->data;
            temp->mini=root->data;
            
          //  cout<<temp->isBst<<" "<<temp->len<<" "<<temp->sum<<" "<<temp->maxi<<" "<<temp->mini<<endl;
            
            return temp;
        }
        
        struct bst* l=solve(root->left,target,mini);
        struct bst* r=solve(root->right,target,mini);
        
        if(l->sum+r->sum+root->data==target)
        {
            struct bst* temp=new bst();
            
            if(l->isBst==false || r->isBst==false)
            {
                temp->isBst=false;
            }
            else if(root->data>l->maxi && root->data<r->mini)
               temp->isBst=true;
            else
               temp->isBst=false;
               
            temp->len=l->len+r->len+1;
            temp->sum=l->sum+r->sum+root->data;
            temp->maxi=max(root->data,max(r->maxi,l->maxi));
            temp->mini=min(root->data,min(l->mini,r->mini));
            
            if(temp->isBst==true)
               mini=min(mini,l->len+r->len+1);
               
            
          //   cout<<temp->isBst<<"+"<<temp->len<<" "<<temp->sum<<" "<<temp->maxi<<" "<<temp->mini<<endl;
               
            return temp;
        }
        else
        {
            struct bst* temp=new bst();
            
            if(l->isBst==false || r->isBst==false)
            {
                temp->isBst=false;
            }
            else if(root->data>l->maxi && root->data<r->mini)
               temp->isBst=true;
            else
               temp->isBst=false;
               
            temp->len=l->len+r->len+1;
            temp->sum=l->sum+r->sum+root->data;
            temp->maxi=max(root->data,max(r->maxi,l->maxi));
            temp->mini=min(root->data,min(l->mini,r->mini));
            
            
            
           // cout<<temp->isBst<<"-"<<temp->len<<" "<<temp->sum<<" "<<temp->maxi<<" "<<temp->mini<<endl;
            
            return temp;
        }
        
    }

    int minSubtreeSumBST(int target, Node *root) {
        
        int mini=1e9;
        struct bst* temp=solve(root,target,mini);
        
        //cout<<temp->isBst<<"-"<<temp->len<<" "<<temp->sum<<" "<<temp->maxi<<" "<<temp->mini<<endl;
            
        if(mini==1e9)
           return -1;
        return mini;
    }
};














//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends