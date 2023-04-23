class Solution {
public:
    
    int mod=1e9+7;
    
    int solve(string &s,int n,int k,int ind,vector<int> &dp)
    {
        //cout<<ind<<endl;
        if(ind==n)
            return 1;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        long long p=0;
        int fact=0;
        int ans=0;
        for(int i=ind;i<n;i++)
        {
            p=p*10+(s[i]-'0');
          //  cout<<p<<endl;
            if(p<=k && p!=0)
            {
                ans=(ans+solve(s,n,k,i+1,dp))%mod;
            }
            else if(p==0 || p>k)
            {
                break;
            }
        }
        
        return dp[ind]=ans;
    }
    
    int numberOfArrays(string s, int k) {
        
        int n=s.length();
        vector<int> dp(n+1,-1);
        return solve(s,n,k,0,dp);
        
    }
};