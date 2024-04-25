class Solution {
public:
    
    int solve(string &s,int ind,int n,int k,char ch,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        
        if(ch!='0' && dp[ind][ch-'a']!=-1)
            return dp[ind][ch-'a'];
        
        if(ch=='0')
        {
            return max(1+solve(s,ind+1,n,k,s[ind],dp),0+solve(s,ind+1,n,k,ch,dp));
        }
        
        int take=0;
        int nottake=0;
        if(abs(s[ind]-ch)<=k)
        {
            take=1+solve(s,ind+1,n,k,s[ind],dp);
        }
        nottake=0+solve(s,ind+1,n,k,ch,dp);
        
        return dp[ind][ch-'a']=max(take,nottake);
    }
    
    int longestIdealString(string s, int k) {
        
        int n=s.length();
        char ch='0';
        vector<vector<int>> dp(n+1,vector<int>(26,-1));
        return solve(s,0,n,k,ch,dp);
    }
};