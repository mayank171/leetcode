class Solution {
public:
    
    int solve(vector<vector<int>> &matrix,int n,int m,int i,int j,vector<vector<int>> &dp)
    {
        if(j==m || j<0)
            return 1e5;
        
        
        if(i==n)
            return 0;
        
        if(dp[i][j]!=-2000)
            return dp[i][j];
        
        int l=solve(matrix,n,m,i+1,j-1,dp);
        int d=solve(matrix,n,m,i+1,j,dp);
        int r=solve(matrix,n,m,i+1,j+1,dp);
        
        return dp[i][j]=matrix[i][j]+min(l,min(d,r));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-2000));
        
        int ans=1e9;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,solve(matrix,n,m,0,i,dp));
        }
        
        return ans;
    }
};