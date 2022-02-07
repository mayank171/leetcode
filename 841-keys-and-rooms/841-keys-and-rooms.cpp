class Solution {
private:
    void bfs(vector<int> adj[],vector<int> &vis)
    {
     
        queue<int> q;
        
        q.push(0);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto &it:adj[node])
            {
                if(vis[it]==0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
public:
    
//     void dfs(vector<vector<int>> rooms, int src, vector<int> &vis)
//     {
//         vis[src]=1;
//         cout<<src<<endl;
        
//         for(auto it: rooms[src])
//         {
//             if(vis[it]==0)
//             {
//                 dfs(rooms,it,vis);
//             }
//         }
//     }
    
//     void bfs(vector<vector<int>> rooms,int src,vector<int> &vis)
//     {
//         vis[src]=1;
//         queue<int> q;
//         q.push(src);
        
//         while(!q.empty())
//         {
//             int x=q.front();
//             q.pop();
            
//             for(auto it: rooms[x])
//             {
//                 if(vis[it]==0)
//                 {
//                     vis[it]=1;
//                     cout<<it<<endl;
//                     q.push(it);
//                 }
//             }
            
//         }
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        
        vector<int> vis(n,0);
        vis[0]=1;
        
        bfs(adj,vis);
        
        for(auto &it:vis)
        {
            cout<<it<<" ";
        }
        
        for(auto &it:vis)
        {
            if(it==0)
                return false;
        }
        return true;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int num_rooms=rooms.size();
        
       
//         vector<int> vis(num_rooms,0);
        
//         bfs(rooms,0,vis);
            
        
//         for(int i=0;i<vis.size();i++)
//         {
//             if(vis[i]==0)
//             {
//                 return false;
//             }
//         }
//         return true;
    }
};