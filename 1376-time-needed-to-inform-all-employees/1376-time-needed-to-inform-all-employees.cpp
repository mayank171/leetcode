class Solution {
public:
    
    
    int dfs(vector<pair<int,int>> adj[],int n,int src,vector<int> & informTime)
    {
        int maxi=0;
        for(auto &it:adj[src])
        {
            int adjnode=it.first;
            maxi=max(maxi,informTime[src]+dfs(adj,n,adjnode,informTime));
        }
        
        return maxi;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<pair<int,int>> adj[n];
        
        
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)
                continue;
            adj[manager[i]].push_back({i,informTime[manager[i]]});
        }
        
//         for(int i=0;i<n;i++)
//         {
//             cout<<i<<"->";
//             for(int j=0;j<adj[i].size();j++)
//             {
//                 cout<<adj[i][j].first<<","<<adj[i][j].second<<" ";
//             }
//             cout<<endl;
//         }
        
        
        int ans=dfs(adj,n,headID,informTime);
        return ans;
//         queue<pair<int,int>> q;
//         q.push({headID,0});
        
//         int ans=informTime[headID];
//         while(!q.empty())
//         {
//             int size=q.size();
//             int maxi=0;
//             for(int i=0;i<size;i++)
//             {
//                 int node=q.front().first;
//                 int t=q.front().second;
                
//                 q.pop();
                
//                 maxi=max(maxi,t);
                
//                 for(auto &it:adj[node])
//                 {
//                     int adjnode=it.first;
//                     if(t>=informTime[adjnode])
//                         q.push({adjnode,informTime[t-informTime[adjnode]]});
//                     else
//                         q.push({adjnode,informTime[adjnode]});
//                 }
//             }
//             ans+=maxi;
//         }
                                      
//         return ans;
        
    }
};