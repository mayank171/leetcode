class Solution {
private:
    int check(int n,vector<int> &dp)
    {
        if(n==1 || n==0)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int l=check(n-1,dp);
        int r=check(n-2,dp);
        
        return dp[n]=l+r;
        
    }
public:
    int climbStairs(int n) {
        
        if(n==1)
            return 1;
        
        vector<int> dp(n+1,-1);
        
        check(n,dp);
        
        return dp[n];
        
    }
};