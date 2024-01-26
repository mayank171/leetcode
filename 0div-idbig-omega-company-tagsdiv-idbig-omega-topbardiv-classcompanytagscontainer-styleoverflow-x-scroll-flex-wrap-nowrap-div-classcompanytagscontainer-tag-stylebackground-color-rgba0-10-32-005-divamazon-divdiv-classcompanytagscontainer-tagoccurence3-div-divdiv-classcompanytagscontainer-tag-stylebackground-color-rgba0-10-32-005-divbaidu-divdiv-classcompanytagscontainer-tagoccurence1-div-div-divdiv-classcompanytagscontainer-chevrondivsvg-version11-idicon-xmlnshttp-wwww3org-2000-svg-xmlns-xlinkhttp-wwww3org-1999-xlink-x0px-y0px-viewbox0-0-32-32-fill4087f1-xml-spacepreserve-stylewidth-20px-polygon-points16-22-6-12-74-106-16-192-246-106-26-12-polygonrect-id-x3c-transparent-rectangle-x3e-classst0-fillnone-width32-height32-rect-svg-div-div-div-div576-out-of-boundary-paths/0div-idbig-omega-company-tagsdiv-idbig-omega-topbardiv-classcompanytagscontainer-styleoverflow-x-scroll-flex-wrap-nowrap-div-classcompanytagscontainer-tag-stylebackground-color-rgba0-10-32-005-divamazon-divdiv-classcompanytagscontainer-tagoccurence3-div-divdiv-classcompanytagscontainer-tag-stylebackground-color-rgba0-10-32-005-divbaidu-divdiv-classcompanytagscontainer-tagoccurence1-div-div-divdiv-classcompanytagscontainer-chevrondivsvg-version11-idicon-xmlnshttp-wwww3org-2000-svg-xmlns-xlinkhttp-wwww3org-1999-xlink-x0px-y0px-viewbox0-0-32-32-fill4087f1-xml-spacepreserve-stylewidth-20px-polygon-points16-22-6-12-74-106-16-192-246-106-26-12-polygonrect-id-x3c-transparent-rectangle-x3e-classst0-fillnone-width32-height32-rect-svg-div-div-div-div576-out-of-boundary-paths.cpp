class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int mod=1e9+7;
    
    int solve(int m,int n,int maxMove, int startRow,int startColumn, vector<vector<vector<int>>> &dp)
    {
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n)
            return 1;
        
        if(maxMove<=0)
            return 0;
        
        if(dp[startRow][startColumn][maxMove]!=-1)
            return dp[startRow][startColumn][maxMove];
        
        int ans=0;
        for(int ind=0;ind<4;ind++)
        {
            int ind_x=dx[ind]+startRow;
            int ind_y=dy[ind]+startColumn;
            
            ans=(ans+solve(m,n,maxMove-1,ind_x,ind_y,dp))%mod;
        }
        
        return dp[startRow][startColumn][maxMove]=ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int> (maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};