class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                int profit=-1e8;
                if(j)
                {
                    profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][j]);
                }
                else
                {
                    if(prices[i]+dp[i+1][1]-fee>0+dp[i+1][j])
                    {
                        profit=prices[i]+dp[i+1][1]-fee;
                    }
                    else
                    {
                        profit=dp[i+1][j];
                    }
                }
                dp[i][j]=profit;
            }
        }
        
        return dp[0][1];
        
    }
};