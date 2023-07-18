class Solution {
public:
    
    int solve(vector<vector<int>> &grid,int n,int m,int i,int j,vector<vector<int>> &dp)
    {
        if(i==n || j==m)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int x=grid[i][j]+solve(grid,n,m,i+1,j,dp);
        int y=grid[i][j]+solve(grid,n,m,i+1,j+1,dp);
        
        return dp[i][j]=min(x,y);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        int m=n;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(triangle,n,m,0,0,dp);
    }
};