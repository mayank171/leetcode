class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(edges.size()==0)
            return {0};
        
        vector<int> indeg(n);
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            indeg[u]++;
            indeg[v]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==1)
            {
                q.push(i);
            }
        }
        
        int ct=n;
        while(ct>2)
        {
            int size=q.size();
            ct-=size;
            
            for(int i=0;i<size;i++)
            {
                int node=q.front();
                q.pop();
                
                for(auto &it:adj[node])
                {
                    indeg[it]--;
                    if(indeg[it]==1)
                        q.push(it);
                }
            }
            
            
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};