class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        
        vector<int> dist(n,1e5);
        vector<int> vis(n,0);
         priority_queue<pair<int,pair<int,int>>> pq;
        
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int d=flights[i][2];
            
            adj[u].push_back({v,d});
        }
        
        k++;
        pq.push({k,{0,src}});
        dist[src]=0;
        
        int ans=1e9;
        while(!pq.empty())
        {
            int kk=pq.top().first;
            int node=pq.top().second.second;
            int dis=pq.top().second.first;
            pq.pop();
            
            if(node==dest)
            {
                ans=min(ans,dis);
               
            }    
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                
                if(dist[adjnode]>=wt+dis && kk-1>=0)
                {
                    dist[adjnode]=wt+dis;
                    pq.push({kk-1,{dist[adjnode],adjnode}});
                }
            }
        }
        
        if(ans==1e9)
            return -1;
        
        return ans;
    }
};