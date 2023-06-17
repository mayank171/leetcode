class Solution {
public:
    int numTilings(int n) {
        
        int mod=1e9+7;
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        if(n==1)
            return 1;
        
        dp[2]=2;
        
        if(n==2)
            return 2;
        
        for(int i=3;i<n+1;i++)
        {
            dp[i]=((2*1ll*(dp[i-1]*1ll*dp[1])%mod)%mod+dp[i-3])%mod;
        }
        
        return dp[n];
    }
};