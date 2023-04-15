class Solution {
public:
    
    int solve(vector<int> &coins,int ind,int n,int amt,vector<vector<int>> &dp)
    {
        if(amt<0)
            return 1e9;
        if(amt==0)
            return 0;
        if(ind>=n)
            return 1e9;
        
        if(dp[ind][amt]!=-1)
            return dp[ind][amt];
        
        int nottake=1e9;
        int take=1e9;
        
        nottake=solve(coins,ind+1,n,amt,dp);
        if(amt>=coins[ind])
           take=1+solve(coins,ind,n,amt-coins[ind],dp);
        
        return dp[ind][amt]=min(nottake,take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        sort(coins.begin(),coins.end());
        
        vector<vector<int>> dp(20,vector<int> (amount+1,-1));
        
        int ans=solve(coins,0,n,amount,dp);
        
        if(ans>=1e9)
            return -1;
        return ans;
    }
};