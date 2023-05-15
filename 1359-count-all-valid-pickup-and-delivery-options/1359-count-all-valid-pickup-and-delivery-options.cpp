class Solution {
public:
    
    
    int countOrders(int n) {
        
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        int mod=1e9+7;
        
        for(int i=2;i<n+1;i++)
        {
            int x=(((2*i-2)+1)*1ll*((2*i-2)+2))%mod;
            x=x/2;
            dp[i]=(dp[i-1]*1ll*x)%mod;
        }
        
        return dp[n];
    }
};