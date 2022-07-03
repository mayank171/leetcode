class Solution {
private:
    int check(vector<vector<int>> &grid,int n,int m,int x,int y)
    {
        if(grid[x][y]==0)
        {
           return 0;    
        }
        
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
       // cout<<x<<" "<<y<<endl;
        vector<int> maxi(4,0);
        
        for(int i=0;i<4;i++)
        {
            int ind_x=x+dx[i];
            int ind_y=y+dy[i];
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m)
            {
                int p=grid[x][y];
                grid[x][y]=0;
                maxi[i]=p+check(grid,n,m,ind_x,ind_y);
                grid[x][y]=p;
            }
        }
        
        int ans=*max_element(maxi.begin(),maxi.end());
       // cout<<"----"<<ans<<endl;
        
        return ans;
        
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=-1e8;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    ans=max(ans,check(grid,n,m,i,j));
                }
            }
        }
        
       if(ans==-1e8)
           return 0;
       return ans;
    }
};