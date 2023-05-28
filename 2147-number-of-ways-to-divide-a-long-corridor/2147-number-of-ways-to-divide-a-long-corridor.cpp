class Solution {
public:
    int mod=1e9+7;
    
    int solve(string &s,int size,int ind,int ctr,vector<vector<int>> &dp)
    {
      //  cout<<ind<<" "<<ctr<<endl;
        if(ind==size)
        {
            if(ctr==2)
                return 1;
            return 0;
        }
        
        if(ctr>2)
            return 0;
        
        if(dp[ind][ctr]!=-1)
            return dp[ind][ctr];
        
        int ways=0;
        if(ctr==2)
        {
            ways=(ways+solve(s,size,ind,0,dp))%mod;    
        }
        
        
        if(s[ind]=='S')
        {
            ways=(ways+solve(s,size,ind+1,ctr+1,dp))%mod;
        }
        else
        {
            ways=(ways+solve(s,size,ind+1,ctr,dp))%mod;
        }
        
        return dp[ind][ctr]=ways;
    }
    
    int numberOfWays(string corridor) {
        
        int size=corridor.size();
        vector<vector<int>> dp(size,vector<int> (3,-1));
        return solve(corridor,size,0,0,dp);
        
    }
};