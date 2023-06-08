class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> dis(n+1,1e9);
        queue<pair<int,int>> pq;
        pq.push({0,k});
        dis[k]=0;
        
        while(!pq.empty())
        {
            int dist=pq.front().first;
            int node=pq.front().second;
            pq.pop();
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                
                if(dist+wt<dis[adjnode])
                {
                    dis[adjnode]=dist+wt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        
        int maxi=0;
        for(int i=1;i<n+1;i++)
        {
            if(i!=k)
               maxi=max(maxi,dis[i]);
        }
        
        return (maxi==1e9)?-1:maxi;
        
    }
};