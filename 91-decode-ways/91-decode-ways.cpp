class Solution {
private:
    
    int check(string &s,int n,vector<int> &dp)
    {
        
        if(n==0)
        {
            return dp[n]=1;
        }
        
        if(dp[n]!=-1)
            return dp[n];
        
        int ct=0;
        if(s[n-1]!='0')
        {
            ct+=check(s,n-1,dp);
        }
        
        if(n>1 && stoi(s.substr(n-2,2))>=10 && stoi(s.substr(n-2,2))<=26)
        {
            ct+=check(s,n-2,dp);
        }
        
        return dp[n]=ct;
    }
    
public:
    int numDecodings(string s) {
        
        int l=s.length();
        
        vector<int> dp(l+1,-1);
        
        int ans=check(s,l,dp);
        
        return ans;
        
    }
};