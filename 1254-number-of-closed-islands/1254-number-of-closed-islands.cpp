class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> vis(n*m,0);
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1)&&(grid[i][j]==0))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                  //  cout<<i<<" "<<j<<endl;
                }
            }
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+x;
                int ind_y=dy[ind]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && grid[ind_x][ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({ind_x,ind_y});
                }
            }
        }
        
//         for(auto &it:vis)
//         {
//             cout<<it<<" ";
            
//         }
        
//         return 0;
        
        int ans=0;
        vector<pair<int,int>> rem;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i*m+j]==0 && grid[i][j]==0)
                {
                    rem.push_back({i,j});
                }
            }
        }
        
        int size=rem.size();
        for(int i=0;i<size;i++)
        {
           // cout<<rem[i].first<<" "<<rem[i].second<<endl;
            if(vis[rem[i].first*m+rem[i].second]==0)
            {
              //  cout<<"cdcd"<<endl;
                queue<pair<int,int>> q;
                q.push({rem[i].first,rem[i].second});

                while(!q.empty())
                {
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();

                    for(int ind=0;ind<4;ind++)
                    {
                        int ind_x=dx[ind]+x;
                        int ind_y=dy[ind]+y;

                        if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && grid[ind_x][ind_y]==0)
                        {
                            q.push({ind_x,ind_y});
                            vis[ind_x*m+ind_y]=1;
                        }                            
                    }
                }
                ans++;   
            }
        }
        
        return ans;
        
    }
};



















