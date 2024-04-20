class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        vector<int> vis(n*m,0);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i*m+j]==0)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    int a,b,c,d;
                    while(!q.empty())
                    {
                        int r=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        
                        if(r-1<0 && col==0 && r==0 && col-1<0)
                        {
                            a=r;
                            b=col;
                        }
                        else if(r-1>=0 && grid[r-1][col]==0 && r>0 && col-1<0)
                        {
                            a=r;
                            b=col;
                        }
                        else if(col-1>=0 && grid[r][col-1]==0 && r-1<0 && col>0)
                        {
                            a=r;
                            b=col;
                        }
                        else if(r-1>=0 && col-1>=0 && grid[r-1][col]==0 && grid[r][col-1]==0)
                        {
                            a=r;
                            b=col;
                        }
                        
                        if(r+1==n && col==m-1 && r==n-1 && col+1==m)
                        {
                            c=r;
                            d=col;
                        }
                        else if(r+1<n && grid[r+1][col]==0 && r<n-1 && col+1==m)
                        {
                            c=r;
                            d=col;
                        }
                        else if(col+1<m && grid[r][col+1]==0 && r+1==n && col<m-1)
                        {
                            c=r;
                            d=col;
                        }
                        else if(r+1<n && col+1<m && grid[r+1][col]==0 && grid[r][col+1]==0)
                        {
                            c=r;
                            d=col;
                        }
                        
                            
                        
                        for(int ind=0;ind<4;ind++)
                        {
                            int ind_x=dx[ind]+r;
                            int ind_y=dy[ind]+col;
                            
                            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==1 && vis[ind_x*m+ind_y]==0)
                            {
                                vis[ind_x*m+ind_y]=1;
                                q.push({ind_x,ind_y});
                            }
                        }
                    }
                    
                    ans.push_back({a,b,c,d});
                }
            }
        }
        
        return ans;
    }
};