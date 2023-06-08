class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];
        int mod=1e9+7;
        
        int size=roads.size();
        
        for(int i=0;i<size;i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<long long> dist(n,1e14);
        vector<long long> ways(n,0);
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        
        while(!pq.empty())
        {
            long long time=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            
            if(node==n-1)
                continue;
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                
                if(time+wt<dist[adjnode])
                {
                    dist[adjnode]=(time+wt);
                    ways[adjnode]=ways[node];
                    pq.push({time+wt,adjnode});
                }
                else if(time+wt==dist[adjnode])
                {
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1];
        
    }
};












