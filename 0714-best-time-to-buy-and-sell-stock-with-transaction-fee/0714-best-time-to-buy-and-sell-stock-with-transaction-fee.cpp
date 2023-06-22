class Solution {
public:
    
    int solve(vector<int> &prices,int n,int ind,int flag,int fee,vector<vector<int>> &dp)
    {
        if(ind==n)
            return 0;
        
        if(dp[ind][flag]!=-1)
            return dp[ind][flag];
        
        if(flag==0)
        {
            int take=-prices[ind]+solve(prices,n,ind+1,1,fee,dp);
            int nottake=0+solve(prices,n,ind+1,flag,fee,dp);
            
            return dp[ind][flag]=max(take,nottake);
        }
        else
        {
            int take=prices[ind]-fee+solve(prices,n,ind+1,0,fee,dp);
            int nottake=solve(prices,n,ind+1,flag,fee,dp);
            
            return dp[ind][flag]=max(take,nottake);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,n,0,0,fee,dp);
    }
};