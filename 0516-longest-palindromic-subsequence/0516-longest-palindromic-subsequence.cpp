class Solution {
public:
    
    int solve(string &a,string &b,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        int ans=0;
        if(a[ind1]==b[ind2])
        {
            ans=1+solve(a,b,ind1-1,ind2-1,dp);
        }
        else
        {
            ans=max(solve(a,b,ind1-1,ind2,dp),solve(a,b,ind1,ind2-1,dp));
        }
        
        return dp[ind1][ind2]=ans;
    }
    
    int longestPalindromeSubseq(string s) {
        
        string a=s;
        string b=s;
        reverse(b.begin(),b.end());
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(a,b,n-1,n-1,dp);
    }
};