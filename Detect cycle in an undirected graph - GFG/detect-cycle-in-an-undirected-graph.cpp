// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    bool check(vector<int> adj[],int src,int V,vector<int> &vis,vector<int> &parent)
    {
        
        vis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                vis[it]=1;
                parent[it]=src;
                if(check(adj,it,V,vis,parent))
                   return true;
            }
            else if(parent[src]!=it)
                 return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        q.push(0);
        vector<int> vis(V,0);
        vis[0]=1;
        vector<int> parent(V,0);
        parent[0]=-1;
        
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(check(adj,i,V,vis,parent))
                   return true;
            }
        }
        
        return false;
        
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto &it:adj[node])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    parent[it]=node;
                    q.push(it);
                }
                else if(parent[node]!=it)
                     return true;
                
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends