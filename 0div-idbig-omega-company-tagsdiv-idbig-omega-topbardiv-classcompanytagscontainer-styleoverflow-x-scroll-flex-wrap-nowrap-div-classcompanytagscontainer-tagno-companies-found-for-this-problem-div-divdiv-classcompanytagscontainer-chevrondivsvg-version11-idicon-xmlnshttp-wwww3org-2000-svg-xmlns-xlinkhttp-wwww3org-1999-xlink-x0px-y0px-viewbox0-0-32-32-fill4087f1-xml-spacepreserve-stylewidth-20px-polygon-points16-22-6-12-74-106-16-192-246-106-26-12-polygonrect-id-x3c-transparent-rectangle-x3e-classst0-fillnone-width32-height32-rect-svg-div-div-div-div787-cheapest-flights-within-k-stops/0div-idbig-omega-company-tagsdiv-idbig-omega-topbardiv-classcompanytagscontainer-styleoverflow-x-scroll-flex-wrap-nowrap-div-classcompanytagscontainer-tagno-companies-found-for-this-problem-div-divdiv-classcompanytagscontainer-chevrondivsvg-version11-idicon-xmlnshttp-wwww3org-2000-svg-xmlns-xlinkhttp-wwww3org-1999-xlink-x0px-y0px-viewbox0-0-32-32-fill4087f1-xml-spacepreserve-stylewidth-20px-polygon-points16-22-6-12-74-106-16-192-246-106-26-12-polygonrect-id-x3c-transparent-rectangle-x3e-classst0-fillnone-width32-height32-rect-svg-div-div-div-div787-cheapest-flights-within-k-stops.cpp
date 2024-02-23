class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        int size=flights.size();
        
        for(int i=0;i<size;i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int cost=flights[i][2];
            
            adj[u].push_back({v,cost});
        }
        
        k++;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({k,{0,src}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(!pq.empty())
        {
            int stops=pq.top().first;
            int d=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
            
            if(node==dst)
            {
                continue;
            }
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int w=it.second;
                if(stops>0 && dist[adjnode]>d+w)
                {
                    dist[adjnode]=d+w;
                    pq.push({stops-1,{dist[adjnode],adjnode}});
                }
            }
        }
        
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};