class Solution {
public:
    
    int solve(vector<int> &cost,int n,int ind,vector<int> &dp)
    {
        if(ind>=n)
            return 0;
        
        if(dp[ind+1]!=-1)
            return dp[ind+1];
        
        int l=0;
        int r=0;
        if(ind+1<n)
           l=cost[ind+1]+solve(cost,n,ind+1,dp);
        
        if(ind+2<n)
           r=cost[ind+2]+solve(cost,n,ind+2,dp);
        
        return dp[ind+1]=min(l,r);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        
        vector<int> dp(n+1,-1);
        return solve(cost,n,-1,dp);
    }
};