class Solution {
public:
    
    
    void dfs(vector<int> adj[],int src,vector<int> &vis)
    {
        vis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                dfs(adj,it,vis);
            }
        }
        
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        
        int edgesSize=edges.size();
        
        for(int i=0;i<edgesSize;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
//         vector<int> vis(n,0);
        
//         for(int i=0;i<n;i++)
//         {
//             if(vis[i]==0)
//             {
//                 q.push(i);
//                 dist[i]=0;
//                 dfs(adj,i,vis);  
//                 cout<<i<<endl;
//             }    
//         }
        
        
        int ans=1e9;
        
        for(int i=0;i<n;i++)
        {
            vector<int> dist(n,1e9);
            vector<int> parent(n,-1);
            queue<int> q;
            dist[i]=0;
            q.push(i);
            while(!q.empty())
            {
                int src=q.front();
               // cout<<src<<" "<<d<<endl;
                q.pop();

                for(auto &it:adj[src])
                {
                    if(dist[it]==1e9)
                    {
                        q.push(it);
                        dist[it]=dist[src]+1;
                        parent[it]=src;
                    }
                    else if(parent[src]!=it && parent[it]!=src)
                    {
                        ans=min(ans,dist[it]+dist[src]+1);
                    }
                }
            }
           
        }
        
        
        
        
        
        if(ans>=1e9)
            return -1;
        
        return ans;
    }
};