//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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




// } Driver Code Ends
//User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:

    void solve(Node* root,int target,int level,int depth,int &ans,int &dp)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->data==target)
        {
           // cout<<level<<" "<<depth<<endl;
            ans=level;
            dp=depth;
            return ;
        }
        if(root->data>target)
        {
            solve(root->left,target,level-1,depth+1,ans,dp);
        }
        else 
        {
            solve(root->right,target,level+1,depth+1,ans,dp);
        }
    }
    
    void solve1(Node* root,int target,set<Node*> &desc,int flag)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->data==target)
        {
           flag=1;
        }
        if(flag==1)
           desc.insert(root);
        solve1(root->left,target,desc,flag);
        solve1(root->right,target,desc,flag);
        
    }


    long long int verticallyDownBST(Node *root,int target){
        
        map<int,map<int,set<Node*>>> mp;
        
        queue<pair<int,pair<int,Node*>>> q;
        q.push({0,{0,root}});
        
        while(!q.empty())
        {
            int level=q.front().first;
            int depth=q.front().second.first;
            Node* node=q.front().second.second;
          //  cout<<level<<" "<<depth<<" ";
            q.pop();
            mp[level][depth].insert(node);
            
            if(node->left)
            {
                q.push({level-1,{depth+1,node->left}});
            }
            if(node->right)
            {
                q.push({level+1,{depth+1,node->right}});
            }
            
        }
        
        // for(auto &it:mp)
        // {
        //     cout<<it.first<<"-->";
        //     for(auto &it1:it.second)
        //     {
        //         cout<<it1.first<<"->";
        //         for(auto &it2:it1.second)
        //         {
        //             cout<<it2->data<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
        
       // return 0;
        
        int level=0;
        int depth=0;
        int ans=-100000;
        int dp=-1;
        solve(root,target,level,depth,ans,dp);
        
        set<Node*> desc;
        
        solve1(root,target,desc,0);
        
       // cout<<ans<<" "<<dp<<endl;
        
        if(ans==-100000)
           return -1;
           
        long long sum=0;
        
        for(auto &it:mp[ans])
        {
            if(it.first>dp)
            {
                for(auto &it1:it.second)
                {
               //     cout<<it1->data<<endl;
                    if(desc.find(it1)!=desc.end())
                       sum+=it1->data;
                    //break;
                }
            }
            
        }
        
        return sum;
    }
};



















//{ Driver Code Starts.

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
   Node* root = new Node(stoi(ip[0]));

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

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        int target;
        cin>>target;
        string newline;
        getline(cin,newline);
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.verticallyDownBST(root, target)<<endl;
   }
   return 0;
}
// } Driver Code Ends