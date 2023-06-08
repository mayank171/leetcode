class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({k+1,{0,src}});
        
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        int ans=1e9;
        while(!pq.empty())
        {
            int stops=pq.top().first;
            int dis=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
            
            
            if(node==dst)
                ans=min(ans,dis);
            
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                
                if(dis+wt<=dist[adjnode] && stops-1>=0)
                {
                    dist[adjnode]=dis+wt;
                    pq.push({stops-1,{dis+wt,adjnode}});
                }
            }
        }
        
        if(ans==1e9)
            return -1;
        
        return ans;
        
    }
};