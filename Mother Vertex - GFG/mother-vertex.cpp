//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    
    void solve(vector<int> adj[],int V,vector<int> &vis,int src,stack<int> &stk)
    {
        vis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                solve(adj,V,vis,it,stk);
            }
        }
        stk.push(src);
        
    }
    
    void dfs1(vector<int> adj[],int V,vector<int> &vis,int src)
    {
        vis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                dfs1(adj,V,vis,it);
            }
        }
        
    }
	
	int findMotherVertex(int V, vector<int>adj[])
	{
	    
	    vector<int> vis(V,0);
	    stack<int> stk;
	           
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	           solve(adj,V,vis,i,stk);
	        }
	    }
	    
	    vector<int> vis1(V,0);
	    
	    dfs1(adj,V,vis1,stk.top());
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis1[i]==0)
	           return -1;
	    }
	    
	    return stk.top();
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends