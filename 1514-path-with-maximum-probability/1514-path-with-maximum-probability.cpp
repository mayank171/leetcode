class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>> pq;
        vector<double> vis(n,0.0);
        vis[start]=1;
        pq.push({1,start});
        
        double ans=0;
        
        while(!pq.empty())
        {
            double prob=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(node==end)
            {
                ans=max(ans,prob);
                
            }
            
            for(auto &it:adj[node])
            {
                if(vis[it.first]<prob*it.second)
                {
                    vis[it.first]=prob*it.second;
                    pq.push({prob*it.second,it.first});
                }
            }
        }
        
        return ans;
    }
};