class Solution {
public:
    
    int solve(vector<vector<int>> &piles,int n,int k,int ind,vector<vector<int>> &dp)
    {
        if(ind>=n || k==0)
            return 0;
        
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        
        int sum1=solve(piles,n,k,ind+1,dp);
        
        int sum2=0;
        int ans=0;
        
        for(int i=0;i<piles[ind].size() && i<k;i++)
        {
            ans+=piles[ind][i];
            sum2=max(sum2,ans+solve(piles,n,k-i-1,ind+1,dp));
        }
        
        return dp[ind][k]=max(sum1,sum2);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n=piles.size();
        
        vector<vector<int>> dp(1001,vector<int>(2001,-1));
            
        return solve(piles,n,k,0,dp);
        
    }
};