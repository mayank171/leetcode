//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long,long long>> adj[n];
        
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        vector<long long> dist(n,1e17);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        dist[0]=0;
        
        vector<long long> ways(n,0);
        ways[0]=1;
        int mod=1e9+7;
        
        while(!pq.empty())
        {
            long long node=pq.top().second;
            long long d=pq.top().first;
            pq.pop();
            
            for(auto &it:adj[node])
            {
                long long adjnode=it.first;
                long long w=it.second;
                long long p=(w+d);
                
                if(p<dist[adjnode])
                {
                    dist[adjnode]=p;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(p==dist[adjnode])
                {
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends