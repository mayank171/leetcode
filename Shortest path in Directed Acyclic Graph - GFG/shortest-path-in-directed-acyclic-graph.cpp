//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<edges.size();i++)
        {
            int src=edges[i][0];
            int dest=edges[i][1];
            int wt=edges[i][2];
            
            adj[src].push_back({dest,wt});
        }
        
        vector<int> dist(N,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        dist[0]=0;
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                
                if(wt+d<=dist[adjnode])
                {
                    dist[adjnode]=wt+d;
                    pq.push({wt+d,adjnode});
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
               dist[i]=-1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends