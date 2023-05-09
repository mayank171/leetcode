class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod=1e9+7;
        
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> dist(n,1e15);
        dist[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        
        while(!pq.empty())
        {
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                
                if(d+wt<dist[adjnode])
                {
                    dist[adjnode]=d+wt;
                    ways[adjnode]=ways[node];
                    pq.push({d+wt,adjnode});
                }
                else if(d+wt==dist[adjnode])
                {
                    long long x=ways[adjnode];
                    x+=ways[node];
                    ways[adjnode]=x%mod;
                }
            }
        }
        
        return ways[n-1];
        
    }
};