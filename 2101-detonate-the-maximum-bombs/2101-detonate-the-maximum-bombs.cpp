class Solution {
    
private:
    
//     void dfs(vector<int> adj[],int src,vector<int> & vis,int &ct)
//     {
//         vis[src]=1;
//         ct++;
        
//         for(auto it:adj[src])
//         {
//             if(vis[it]==0)
//                 dfs(adj,it,vis,ct);
//         }
//     }
    
    
    void dfs(int src,vector<int> adj[],vector<int> &vis,int &ct)
    {
        vis[src]=1;
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
            {
                 ct++;
                dfs(it,adj,vis,ct);
            }
        }
    }
    
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        
        int n=bombs.size();
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            int x=bombs[i][0];
            int y=bombs[i][1];
            int rad=bombs[i][2];
            
            for(int j=0;j<n;j++)
            {
                if(j==i)
                    continue;
                double dis=0.0;
                int x_1=bombs[j][0];
                int y_1=bombs[j][1];
                int rad_1=bombs[j][2];
                
                dis=sqrt(pow(x_1-x,2)+pow(y_1-y,2));
                
                if(dis<=rad)
                {
                    adj[i].push_back(j);
                }
            }
            
        }
        
//         for(int i=0;i<n;i++)
//         {
//             cout<<i<<"->";
//             for(int j=0;j<adj[i].size();j++)
//             {
//                 cout<<adj[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            int ct=0;
            dfs(i,adj,vis,ct);
            maxi=max(ct,maxi);
        }
        
        
        
        return maxi+1;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int n=bombs.size();
      
//         vector<int> adj[n];
//         for(int i=0;i<n;i++)
//         {
            
//             for(int j=0;j<n;j++)
//             {
//                 if(i!=j)
//                 {
//                     int x1=bombs[i][0];
//                     int y1=bombs[i][1];
//                     int x2=bombs[j][0];
//                     int y2=bombs[j][1];
                    
//                     float dis1=(float)sqrt(pow(x1-x2,2)+pow(y1-y2,2));
                    
//                     if(dis1<=bombs[i][2])
//                     {
//                         adj[i].push_back(j);
//                     }
//                 }
//             }
          
//         }
    
  
//         int max=INT_MIN;
//         int ct=0;
//         for(int i=0;i<n;i++)
//         {
//             vector<int> vis(n,0);
//             ct=0;
//             dfs(adj,i,vis,ct);
            
//             if(ct>max)
//             {
//                max=ct;
//             }
                
//         }
        
        
//         return max;
        
    }
};