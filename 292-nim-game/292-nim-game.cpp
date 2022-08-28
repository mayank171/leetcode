class Solution {
public:
    
    bool solve(int n,vector<bool> &dp,vector<bool> &done)
    {
        if(n==1 || n==2 || n==3)
            return true;
        
        if(done[n]==true)
            return dp[n];
        
        bool ans1=solve(n-1,dp,done);
        if(ans1==false)
            return true;
        bool ans2=solve(n-2,dp,done);
        if(ans2==false)
            return true;
        bool ans3=solve(n-3,dp,done);
        if(ans3==false)
            return true;
        done[n]=true;
        return dp[n]=false;
    }
    
    bool canWinNim(int n) {
        
        // vector<bool> dp(n+1,false);
        // vector<bool> done(n+1,false);
        // return solve(n,dp,done);
        if(n%4==1 || n%4==2 || n%4==3)
            return true;
        
        return false;
        
    }
};