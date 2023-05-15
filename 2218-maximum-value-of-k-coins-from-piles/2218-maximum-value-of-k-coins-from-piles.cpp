class Solution {
public:
    
    int solve(vector<vector<int>> &piles,int n,int ind,int k,vector<vector<int>> &dp)
    {
       // cout<<ind<<" "<<k<<endl;
        if(ind>=n)
        {
            if(k==0)
                return 0;
            return -1e5;
        }
        
        if(k==0)
        {
            return 0;
        }
        
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        
        int nottake=0;
        nottake=solve(piles,n,ind+1,k,dp);
        
        int take=0;
        int sum=0;
        for(int i=0;i<piles[ind].size() && i<k;i++)
        {
            sum+=piles[ind][i];
            take=max(take,sum+solve(piles,n,ind+1,k-i-1,dp));
        }
                     
        return dp[ind][k]=max(take,nottake);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n=piles.size();
        vector<vector<int>> dp(2001,vector<int> (2001,-1));
        return solve(piles,n,0,k,dp);
    }
};