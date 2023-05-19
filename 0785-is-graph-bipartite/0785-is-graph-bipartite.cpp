class Solution {
public:
    
    bool solve(vector<int> adj[],int src,int n,vector<int> &color)
    {
        for(auto &it:adj[src])
        {
            if(color[it]==-1)
            {
                color[it]=abs(1-color[src]);
                if(!solve(adj,it,n,color))
                    return false;
            }
            else if(color[it]==color[src])
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<int> adj[n];
        
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int u=i;
                int v=graph[i][j];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!solve(adj,i,n,color))
                    return false;
            }
        }
        
        return true;
        
    }
};