class Solution {
public:
    
    
    
    bool dfs(int start,vector<int> adj[],int end,vector<int> &vis)
    {
        vis[start]=1;
        
        for(auto it:adj[start])
        {
            if(vis[it]==0)
            {
                 if(it==end)
                    return true;
            
                 if(dfs(it,adj,end,vis))
                    return true;
            }
           
            
        }
        
        return false;
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        
        if(edges.size()==0)
            return true;
        
        vector<int> adj[n];
        
        
        
        int size=edges.size();
        
        for(int i=0;i<size;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        cout<<"vndv";
        
        vector<int> vis(n,0);
        
        return dfs(start,adj,end,vis);
        
        
    }
};