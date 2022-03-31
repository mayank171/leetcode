class Solution {
private:
//     int check(int n,vector<int> &dp)
//     {
//         if(n==1 || n==0)
//             return 1;
        
//         if(dp[n]!=-1)
//             return dp[n];
        
//         int l=check(n-1,dp);
//         int r=check(n-2,dp);
        
//         return dp[n]=l+r;
        
//     }
public:
    int climbStairs(int n) {
        
        if(n==1)
            return 1;
        
//         vector<int> dp(n+1,-1);
        
//         check(n,dp);
        
//         return dp[n];
        
        vector<int> dp(n+1,-1);
        
        for(int i=0;i<=n;i++)
        {
            if(i<=1)
            {
                dp[i]=1;
                continue;
            }
            
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};