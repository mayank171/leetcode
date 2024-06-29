class Solution {
public:
    
    
    void dfs(vector<int> adj[],int src,vector<int> &vis,vector<int> &temp)
    {
        vis[src]=1;
        
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                temp.push_back(it);
                dfs(adj,it,vis,temp);        
            }
        }
        
    }
    
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        int size=edges.size();
        
        for(int i=0;i<size;i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            vector<int> vis(n,0);
            dfs(adj,i,vis,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        
        
        return ans;
    }
};