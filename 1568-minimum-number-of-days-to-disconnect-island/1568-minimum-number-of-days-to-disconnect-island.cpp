class Solution {
public:
    int numIslands(vector<vector<int>> &grid,int n,int m)
    {
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        vector<int> vis(n*m,0);
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i*m+j]==0)
                {
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i*m+j]=1;
                    
                    while(!q.empty())
                    {
                        int ii=q.front().first;
                        int jj=q.front().second;
                        q.pop();
                        
                        for(int ind=0;ind<4;ind++)
                        {
                            int ind_x=dx[ind]+ii;
                            int ind_y=dy[ind]+jj;
                            
                            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && grid[ind_x][ind_y]==1)
                            {
                                vis[ind_x*m+ind_y]=1;
                                q.push({ind_x,ind_y});
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
    int minDays(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int islands=numIslands(grid,n,m);
        
        cout<<islands<<endl;
        
        if(islands==0 || islands>1)
            return 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    int ans=numIslands(grid,n,m);
                    
                    if(ans==0)
                        return 1;
                    
                    if(ans>1)
                        return 1;
                    
                    grid[i][j]=1;
                }
            }
        }
        
        return 2;
    }
};