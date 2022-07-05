class Solution {
public:
    void dfs(vector<vector<int>> &grid,int n,int m,int x,int y, int color,vector<int> &vis)
    {
        vis[x*m+y]=1;
        int ct=0;
        grid[x][y]=(-1)*grid[x][y];
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int ind_x=dx[i]+x;
            int ind_y=dy[i]+y;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m)
            {
                
                if(abs(grid[ind_x][ind_y])==abs(grid[x][y]))
                {
                    ct++;
                    if(vis[ind_x*m+ind_y]==0)
                        dfs(grid,n,m,ind_x,ind_y,color,vis);
                }
            }
        }
        
        if(ct==4)
        {
            grid[x][y]=abs(grid[x][y]);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> vis(n*m,0);
        
        dfs(grid,n,m,row,col,color,vis);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]<0)
                    grid[i][j]=color;
            }
        }
        
        return grid;
    }
};