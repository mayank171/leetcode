class Solution {
private:
    int check(vector<vector<int>> &dp,vector<vector<int>> &grid,int n,int m,int x,int y,int cur,int &ans)
    {
        //cout<<cur<<endl;
        if(x==0 && y==0)
        {
            return dp[x][y]=grid[x][y];
        }
        
        if(x<0 || y<0)
            return 100000;
        
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        
       
        int l=grid[x][y]+check(dp,grid,n,m,x-1,y,cur,ans);
        int r=grid[x][y]+check(dp,grid,n,m,x,y-1,cur,ans);
        
        return dp[x][y]=min(l,r);
        
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int ans=INT_MAX;
        
        int cur=grid[n-1][m-1];
        
        
        check(dp,grid,n,m,n-1,m-1,cur,ans);
        
        return dp[n-1][m-1];
    }
};