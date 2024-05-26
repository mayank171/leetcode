class Solution {
public:
    
    int mod=1e9+7;
    int solve(int n,int cta,int ctl,vector<vector<vector<int>>> &dp)
    {
        if(n==0)
        {
            if(cta<=1 && ctl<=2)
                return 1;
            return 0;
        }
        
        if(dp[n][cta][ctl]!=-1)
            return dp[n][cta][ctl];
        
        //present
        int x=solve(n-1,cta,0,dp);
        
        //absent
        int y=0;
        if(cta<1)
        {
            y=solve(n-1,cta+1,0,dp);
        }
        //late
        int z=0;
        if(ctl<2)
        {
            z=solve(n-1,cta,ctl+1,dp);
        }
        
        return dp[n][cta][ctl]=(x+(y+z)%mod)%mod;
    }
    
    int checkRecord(int n) {
        
        int cta=0;
        int ctl=0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (3,vector<int> (3,-1)));
        return solve(n,cta,ctl,dp);
    }
    
    
    
    
};