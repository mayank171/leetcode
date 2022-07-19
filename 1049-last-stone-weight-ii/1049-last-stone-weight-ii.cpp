class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int n=stones.size();
        int sum=accumulate(stones.begin(),stones.end(),0);
        
        vector<vector<int>> dp(n,vector<int> (sum+1,0));
        
        dp[0][stones[0]]=1;
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                int take=0;
                if(stones[i]<=j)
                    take=dp[i-1][j-stones[i]];
                int notTake=dp[i-1][j];
                dp[i][j]=take|notTake;
            }
        }
        
        
        int mini=1e8;
        
        for(int i=0;i<sum+1;i++)
        {
            if(dp[n-1][i]!=0 && sum-i-i>=0)
                mini=min(mini,sum-i-i);
        }
        
        return mini;
    }
};