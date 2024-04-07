class Solution {
public:
    
    int solve(string &s,int n,int ind,int ct,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(ct==0)
                return 1;
            return 0;
        }
        
        if(ct<0)
            return false;
        
        if(dp[ind][ct]!=-1)
            return dp[ind][ct];
        
        if(s[ind]=='(')
        {
            if(solve(s,n,ind+1,ct+1,dp))
                return dp[ind][ct]=1;
        }
        else if(s[ind]==')')
        {
            if(solve(s,n,ind+1,ct-1,dp))
                return dp[ind][ct]=1;    
        }
        else
        {
            int x=solve(s,n,ind+1,ct+1,dp);
            int y=solve(s,n,ind+1,ct-1,dp);
            int z=solve(s,n,ind+1,ct,dp);
            if(x==1 || y==1 || z==1)
              return dp[ind][ct]=1;
        }
        
        return dp[ind][ct]=0;
    }
    
    bool checkValidString(string s) {
        
        int n=s.length();
        int ct=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,n,0,ct,dp);
    }
};