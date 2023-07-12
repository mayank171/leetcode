class Solution {
public:
    
    bool dfs(vector<int> adj[],int n,int src,vector<int> &vis,vector<int> &dfsvis)
    {
        vis[src]=1;
        dfsvis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
               if(dfs(adj,n,it,vis,dfsvis))
                   return true;
            }
            else if(dfsvis[it]==1)
            {
                return true;
            }
        }
        
        dfsvis[src]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(!dfs(adj,n,i,vis,dfsvis))
                {
                }
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1 && dfsvis[i]==1)
            {}
            else
                ans.push_back(i);
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};