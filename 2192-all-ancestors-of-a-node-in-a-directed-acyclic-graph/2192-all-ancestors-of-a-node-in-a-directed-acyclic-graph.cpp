class Solution {
public:
    
    
     void dfs(vector<int> adj[],int src,vector<int> &vis,map<int,set<int>> &mp,int node,vector<int> &temp)
    {
        vis[src]=1;
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                temp.push_back(it);
                dfs(adj,it,vis,mp,node,temp);

            }
        }
        
    }
    
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        int size=edges.size();
        
        vector<int> indeg(n,0);
        for(int i=0;i<size;i++)
        {
            indeg[edges[i][1]]++;
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int>> ans;
        map<int,set<int>> mp;
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
        
            vector<int> temp;
             dfs(adj,i,vis,mp,i,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};