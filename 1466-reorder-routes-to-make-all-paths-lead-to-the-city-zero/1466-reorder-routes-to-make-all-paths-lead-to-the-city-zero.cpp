class Solution {
public:
    
    
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        
        vector<int> adj[n];
        
        for(int i=0;i<connections.size();i++)
        {
           int x=connections[i][0];
            int y=connections[i][1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
            

        }
        
        set<pair<int,int>> st;
        
        for(int i=0;i<connections.size();i++)
        {
            st.insert({connections[i][0],connections[i][1]});
        }
        
        int ct=0;
        
        queue<int> q;
        
        vector<int> vis(n,0);
        
        q.push(0);
        
        vis[0]=1;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto &it:adj[node])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    if(st.find({node,it})!=st.end())
                    {
                        ct++;
                    }    
                    q.push(it);
                }
                
            }
        }
        
        return ct;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         vector<int> adj[n];
        
//         set<pair<int,int>> s;
        
//         for(int i=0;i<connections.size();i++)
//         {
//             s.insert({connections[i][0],connections[i][1]});
//         }
        
//         for(int i=0;i<connections.size();i++)
//         {
//             adj[connections[i][0]].push_back(connections[i][1]);
//             adj[connections[i][1]].push_back(connections[i][0]);
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<adj[i].size();j++)
//             {
//                 cout<<adj[i][j]<<" ";
//             }
            
//             cout<<endl;
//         }
        
        
//         vector<int> vis(n,0);
        
//         queue<int> q;
        
//         q.push(0);
        
//         vis[0]=1;
        
        
//         int ct=0;
        
//         while(!q.empty())
//         {
//             int x=q.front();
            
//             q.pop();
            
//             for(auto it:adj[x])
//             {
//                 if(vis[it]==0)
//                 {
//                     vis[it]=1;
//                     q.push(it);
//                     auto it1=s.find({x,it});
//                     if(it1!=s.end())
//                     {
//                         ct++;
//                     }
//                 }
//             }
//         }
        
        
        
//         return ct;
        
    }
};