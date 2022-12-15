//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
Node* solve(vector<int> &in,vector<int> &level,int left,int right,int n,map<int,int> &mp)
{
    if(level.size()==0)
    {
        return NULL;
    }
    
    Node* node=new Node(level[0]);
    
    vector<int> lols;
    vector<int> lors;
    set<int> st;
    int size=level.size();
    
    for(int i=0;i<mp[level[0]];i++)
    {
       // cout<<in[i]<<" ";
        st.insert(in[i]);
    }
  //  cout<<endl;
    
    for(int i=1;i<size;i++)
    {
        if(st.find(level[i])!=st.end())
        {
            lols.push_back(level[i]);
        }
        else
        {
            lors.push_back(level[i]);
        }
    }
    
    node->left=solve(in,lols,left,right,n,mp);
    node->right=solve(in,lors,left,right,n,mp);
    
    return node;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    vector<int> in;
    vector<int> level;
    map<int,int> mp;
    
    for(int i=0;i<n;i++)
    {
        mp[inorder[i]]=i;
        in.push_back(inorder[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        level.push_back(levelOrder[i]);
    }
    
    
    
    
    return solve(in,level,iStart,iEnd,n,mp);
}