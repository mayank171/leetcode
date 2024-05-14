class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    int solve(vector<vector<int>> &grid,int n,int m,int i,int j,vector<int> &vis)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return 0;
        
        vis[i*m+j]=1;
        int maxi=0;
        for(int ind=0;ind<4;ind++)
        {
            int ind_x=dx[ind]+i;
            int ind_y=dy[ind]+j;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0 && grid[ind_x][ind_y]!=0)
            {
                maxi=max(maxi,solve(grid,n,m,ind_x,ind_y,vis));
                
            }
        }
        
        
        vis[i*m+j]=0;
        return grid[i][j]+maxi;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    vector<int> vis(n*m,0);
                    
                    int ans=solve(grid,n,m,i,j,vis);
                    cout<<ans<<endl;
                    res=max(res,ans);
                }
            }
        }
        
        return res;
    }
};