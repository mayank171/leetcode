class Solution {
public:
    int mod=1e9+7;
    
    int solve(vector<int> &v,int n,int start,int finish,int fuel,vector<vector<int>> &dp)
    {
        if(dp[start][fuel]!=-1)
            return dp[start][fuel];
        
        int ct=0;
        if(start==finish)
            ct=(ct+1)%mod;
        
        for(int i=0;i<n;i++)
        {
            if(start!=i && abs(v[start]-v[i])<=fuel)
            {
                if(v[i]==finish)
                   ct=(ct+solve(v,n,i,finish,fuel-abs(v[start]-v[i]),dp))%mod;
                else
                   ct=(ct+solve(v,n,i,finish,fuel-abs(v[start]-v[i]),dp))%mod;
            }
        }
        
        return dp[start][fuel]=ct;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n=locations.size();
        int flag=0;
        vector<vector<int>> dp(n+1,vector<int>(fuel+1,-1));
        return solve(locations,n,start,finish,fuel,dp);
    }
};