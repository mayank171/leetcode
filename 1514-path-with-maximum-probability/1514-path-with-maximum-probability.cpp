class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
            
        }
        
        vector<double> dis(n,0.0);
        
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        
        
        
        while(!pq.empty())
        {
            double dist=pq.top().first;
            int node=pq.top().second;
            //cout<<dist<<" "<<node<<endl;
            pq.pop();
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                double wt=it.second;
                
                if(dist*wt>dis[adjnode])
                {
                    dis[adjnode]=dist*wt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        
        // for(auto &it:dis)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        return dis[end];
    }
};