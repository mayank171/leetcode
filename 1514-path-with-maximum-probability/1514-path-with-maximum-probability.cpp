class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int end) {
        
        vector<pair<int,double>> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        
        vector<double> dist(n,0);
        priority_queue<pair<double,int>> pq;
        
        pq.push({1,src});
        dist[src]=1;
        
        double ans=0;
        
        while(!pq.empty())
        {
            double d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
           // cout<<node<<" "<<d<<endl;
            
            if(node==end)
            {
                ans=max(ans,d);
                continue;
            }
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                double wt=it.second;
                
                if(wt*d>dist[adjnode])
                {
                    dist[adjnode]=wt*d;
                    pq.push({d*wt,adjnode});
                }
            }
        }
        
        return dist[end];
    }
};