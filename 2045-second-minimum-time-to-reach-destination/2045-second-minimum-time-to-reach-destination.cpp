class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<pair<int,int>> adj[n+1]; 
        int size=edges.size();
        
        for(int i=0;i<size;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        
        vector<int> dist1(n+1,1e9);
        vector<int> dist2(n+1,1e9);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
      //  dist1[1]=0;
       // dist2[1]=0;
        vector<int> freq(n+1,0);
        
        while(!pq.empty())
        {
            int tt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            freq[node]++;
            
            if(freq[node]==2 && node==n)
            {
                return tt;
            }
            
            if((tt/change)&1)
            {
                tt=change*(tt/change+1)+time;
            }
            else
            {
                tt=tt+time;
            }
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                
                if(tt<dist1[adjnode])
                {
                    dist2[adjnode]=dist1[adjnode];
                    dist1[adjnode]=tt;
                    pq.push({tt,adjnode});
                }
                else if(tt<dist2[adjnode] && tt!=dist1[adjnode])
                {
                    dist2[adjnode]=tt;
                    pq.push({tt,adjnode});
                }
            }
        }
        
        return 0;
    }
};