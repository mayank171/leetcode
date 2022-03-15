// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    void check(int src,int dest,vector<int> adj[],int &ct)
    {
        for(auto &it:adj[src])
        {
            if(it==dest)
            {
                ct++;
            }
            else
            {
                check(it,dest,adj,ct);
            }
        }
    }
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int src, int dest) {
        // Code here
        
        
        
        int ct=0;
        
        if(src==dest)
          ct=1;
        
        check(src,dest,adj,ct);
        
        return ct;
        
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends