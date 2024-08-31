class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<double> dist(n,0);
        priority_queue<pair<double,int>> q;
        q.push({1,start});
        dist[start]=1;
        
        while(!q.empty())
        {
            double d=q.top().first;
            int node=q.top().second;
            q.pop();
            
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                double wt=it.second;
                
                if(dist[adjnode]<wt*d)
                {
                    dist[adjnode]=wt*d;
                    q.push({wt*d,adjnode});
                }
            }
        }
        
        if(dist[end]==1)
            return 0;
        
        return dist[end];
    }
};