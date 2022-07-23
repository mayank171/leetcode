class Solution {
public:
    int maxProfit(int val, vector<int>& prices) {
        
        int n=prices.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(val+1,0)));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
               for(int k=1;k<val+1;k++)
               {
                   int profit=-1e8;
                   if(j)
                   {
                       profit=max(-prices[i]+dp[i+1][0][k],0+dp[i+1][j][k]);
                   }
                   else
                   {
                       profit=max(prices[i]+dp[i+1][1][k-1],0+dp[i+1][j][k]);    
                   }
                   dp[i][j][k]=profit;
               }
            }
        }
        
        return dp[0][1][val];
        
    }
};