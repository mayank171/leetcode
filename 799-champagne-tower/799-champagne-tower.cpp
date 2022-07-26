class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
     
        double p=poured;
        vector<vector<double>> dp(101,vector<double>(101,0));
        dp[0][0]=p;
        for(int i=0;i<query_row+1;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(dp[i][j]>1)
                {
                    p=dp[i][j]-1;
                    dp[i][j]=1;
                    dp[i+1][j]+=p/2.0;
                    dp[i+1][j+1]+=p/2.0;
                }
                
            }
         
            
        }
        
     
        return dp[query_row][query_glass];
    }
};