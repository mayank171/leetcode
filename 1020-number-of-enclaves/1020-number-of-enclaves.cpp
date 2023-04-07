class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> vis(n*m,0);
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1)&&(grid[i][j]==1))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
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
            
            for(int i=0;i<4;i++)
            {
                int ind_x=dx[i]+x;
                int ind_y=dy[i]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==1 && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({ind_x,ind_y});
                }
            }
        }
        
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i*m+j]==0)
                {
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};



















