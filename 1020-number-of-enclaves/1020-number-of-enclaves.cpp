class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,vector<int> &vis,int x,int y,int n,int m,int &ones)
    {
        vis[x*m+y]=1;
        ones--;
            
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int ind_x=dx[i]+x;
            int ind_y=dy[i]+y;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==1 && vis[ind_x*m+ind_y]==0)
            {
                
                dfs(grid,vis,ind_x,ind_y,n,m,ones);
            }
        }
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int ones=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ones++;
            }
        }
        
        vector<int> vis(n*m,0);
        
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 && vis[i]==0)
            {
                dfs(grid,vis,0,i,n,m,ones);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(grid[n-1][i]==1 && vis[(n-1)*m+i]==0)
            {
                dfs(grid,vis,n-1,i,n,m,ones);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 && vis[i*m]==0)
            {
                dfs(grid,vis,i,0,n,m,ones);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]==1 && vis[i*m+m-1]==0)
            {
                dfs(grid,vis,i,m-1,n,m,ones);
            }
        }
        
        
        
        
        
        
        return ones;
    }
};