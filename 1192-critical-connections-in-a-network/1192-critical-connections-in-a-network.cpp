class Solution {
public:
    
    void findBridges(vector<int> v[],int n,vector<int> &disc,vector<int> &low,vector<vector<int>> &bridges,int src,vector<int> &parent)
    {
        static int time=0;
        disc[src]=low[src]=time;
        time++;
        
        for(auto &it:v[src])
        {
            if(disc[it]==0)
            {
                parent[it]=src;
                findBridges(v,n,disc,low,bridges,it,parent);
                low[src]=min(low[it],low[src]);
                
                if(low[it]>disc[src])
                {
                    bridges.push_back({it,src});
                }
            }
            else if(it!=parent[src])
            {
                low[src]=min(low[src],disc[it]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        
        vector<int> adj[n];
        
        int size=connections.size();
        
        for(int i=0;i<size;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int> disc(n,0);
        vector<int> low(n,0);
        vector<vector<int>> bridges;
        vector<int> parent(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(disc[i]==0)
            {
                findBridges(adj,n,disc,low,bridges,i,parent);
            }
        }
        
        return bridges;
    }
};