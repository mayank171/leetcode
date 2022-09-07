class Solution {
public:
    
    int solve(string &s,int n,int ind,int flag,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        
        if(dp[ind][flag]!=-1)
            return dp[ind][flag];
        
        int ct=0;
        if(s[ind]=='1')
        {
            if(flag==0)
            {
                int l=1+solve(s,n,ind+1,flag,dp);
                int r=0+solve(s,n,ind+1,1,dp);
                ct=min(l,r);
            }
            else
            {
                ct=solve(s,n,ind+1,flag,dp);
            }
        }
        else
        {
            if(flag==1)
            {
                ct=1+solve(s,n,ind+1,flag,dp);
            }
            else
            {
                ct=solve(s,n,ind+1,flag,dp);
            }
        }
        
        return dp[ind][flag]=ct;
    }
    
    int minFlipsMonoIncr(string s) {
        
        int n=s.length();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        int flag=0;
        return solve(s,n,0,flag,dp);
        
        
    }
};