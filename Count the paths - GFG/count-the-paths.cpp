// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(vector<int> adj[],int src,vector<int> &vis,int &ct,int dest)
    {
        if(src==dest)
        {
            ct++;
            return ;
        }
      //  cout<<src<<endl;
       vis[src]=1;
       for(auto &it:adj[src])
       {
           if(vis[it]==0)
           {
               dfs(adj,it,vis,ct,dest);
               
           }
       }
      vis[src]=0;
       
    }
    
    
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<int> adj[n];
	    int size=edges.size();
	    
	    for(int i=0;i<size;i++)
	    {
	        adj[edges[i][0]].push_back(edges[i][1]);
	        
	    }
	    
	    vector<int> vis(n,0);
	    int ct=0;
	    dfs(adj,s,vis,ct,d);
	    
	    return ct;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends