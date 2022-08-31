class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]!=0)
               dp[i][0]=1;
        }
        
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]!=0)
               dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    continue;
                }
                else if(dp[i-1][j]==dp[i][j-1] && dp[i-1][j]==dp[i-1][j-1])
                {
                    dp[i][j]=dp[i-1][j]+1;
                }
                else 
                {
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //cout<<dp[i][j]<<" ";
                ans+=dp[i][j];
            }
            //cout<<endl;
        }
        
        return ans;
        
    }
};