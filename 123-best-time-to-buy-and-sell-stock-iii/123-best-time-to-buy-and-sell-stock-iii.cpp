class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=1;j>=0;j--)
//             {
//                 for(int k=1;k<3;k++)
//                 {
//                     int profit=-1e8;
//                     if(j)
//                        profit=max(-prices[i]+dp[i+1][0][k],0+dp[i+1][j][k]);
//                     else
//                        profit=max(prices[i]+dp[i+1][1][k-1],0+dp[i+1][j][k]);
//                     dp[i][j][k]=profit;
//                 }
//             }
//         }
        
//         return dp[0][1][2];
        
        vector<vector<int>> dp1(2,vector<int>(3,0));
        vector<vector<int>> dp2(2,vector<int>(3,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                for(int k=1;k<3;k++)
                {
                    int profit=-1e8;
                    if(j)
                        profit=max(-prices[i]+dp1[0][k],0+dp1[j][k]);
                    else
                        profit=max(prices[i]+dp1[1][k-1],0+dp1[j][k]);
                    dp2[j][k]=profit;
                }
            }
            dp1=dp2;
        }
        
        
        return dp1[1][2];
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};