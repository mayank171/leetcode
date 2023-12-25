class Solution {
public:
    
    int solve(string &s,int n,int ind,vector<int> &dp)
    {
        if(ind==n)
        {
            return 1;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        
        int x=0;
        int ct=0;
        for(int i=ind;i<n;i++)
        {
            x=x*10+(s[i]-'0');
            if(x==0)
            {
                break;
            }
            else if(x>=1 && x<=26)
            {
                ct+=solve(s,n,i+1,dp);
            }
            else if(x>26)
            {
                break;
            }
        }
        
        return dp[ind]=ct;
    }
    
    int numDecodings(string s) {
        
        int n=s.length();
        
        vector<int> dp(n+1,-1);
        
        return solve(s,n,0,dp);
    }
};

/*



*/