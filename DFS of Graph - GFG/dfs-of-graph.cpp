//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void solve(int v,vector<int> adj[],int ind,vector<int> &ans,vector<int> &vis)
    {
        ans.push_back(ind);
        vis[ind]=1;
        
        for(auto &it:adj[ind])
        {
            if(vis[it]==0)
            {
                solve(v,adj,it,ans,vis);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                solve(V,adj,i,ans,vis);        
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends