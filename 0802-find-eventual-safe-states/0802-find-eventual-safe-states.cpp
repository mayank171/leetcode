class Solution {
public:
    
    bool dfs(vector<int> graph[],int src,vector<int> &vis,vector<int> &dfsvis,set<int> &st)
    {
        cout<<src<<endl;
       
        vis[src]=1;
        dfsvis[src]=1;
        
        for(auto &it:graph[src])
        {
            
            if(vis[it]==0)
            {
               
                if(dfs(graph,it,vis,dfsvis,st))
                {
                    st.insert(src);
                    return true;
                }
                
            }
            else if(dfsvis[it]==1)
            {
                st.insert(src);
                return true;
            }
  
        }
        
        dfsvis[src]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<int> adj[n];
          set<int> st;
        
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<graph[i].size();j++)
            {
                if(graph[i][j]==i)
                    flag=1;
                adj[i].push_back(graph[i][j]);
            }
            if(flag==1)
               st.insert(i);
        }
        
        vector<int> vis(n,0);
      
        vector<int> dfsvis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(adj,i,vis,dfsvis,st);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(st.find(i)!=st.end())
                continue;
            ans.push_back(i);
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};