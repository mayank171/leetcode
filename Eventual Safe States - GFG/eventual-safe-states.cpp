//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool dfs(vector<int> adj[],int src,vector<int> &vis,vector<int> &dfsvis,int V,vector<int> &ans)
    {
        dfsvis[src]=1;
        vis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                if(dfs(adj,it,vis,dfsvis,V,ans))
                   return true;
            }
            else if(dfsvis[it]==1)
            {
                return true;
            }
        }
        
        dfsvis[src]=0;
        ans.push_back(src);
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        vector<int> dfsvis(V,0);
        vector<int> ans;
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(adj,i,vis,dfsvis,V,ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends