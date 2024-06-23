class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod=1e9+7;
        vector<pair<long,long>> adj[n];
        
        int size=roads.size();
        
        for(int i=0;i<size;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        vector<long> dist(n,1e15+10);
        vector<long> parent(n,-1);
        vector<long> count(n,0);
        
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;
        pq.push({0,0});
        count[0]=1;
        dist[0]=0;
        
        while(!pq.empty())
        {
            long d=pq.top().first;
            long node=pq.top().second;
            pq.pop();
            
           // cout<<d<<" "<<node<<endl;
            if(node==n-1)
                continue;
            
            for(auto &it:adj[node])
            {
                long adjnode=it.first;
                long wt=it.second;
                if(d+wt<dist[adjnode])
                {
                    dist[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                    parent[adjnode]=node;
                    count[adjnode]=count[node];
                }
                else if(d+wt==dist[adjnode])
                {
                    count[adjnode]=(count[adjnode]+count[node])%mod;
                }
            }
        }
        
        
//         for(auto &it:dist)
//             cout<<it<<" ";
//         cout<<endl;
        
//         for(auto &it:count)
//             cout<<it<<" ";
//         cout<<endl;
        
        return count[n-1];
    }
};