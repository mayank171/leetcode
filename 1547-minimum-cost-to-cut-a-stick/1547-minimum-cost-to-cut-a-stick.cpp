class Solution {
public:
    
    int solve(vector<int> &cuts,int n,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int mini=1e9;
        for(int k=i;k<=j;k++)
        {
            mini=min(mini,cuts[j+1]-cuts[i-1]+solve(cuts,cuts[k]-i,i,k-1,dp)+solve(cuts,n-cuts[k],k+1,j,dp));
        }
        
        return dp[i][j]=mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        reverse(cuts.begin(),cuts.end());
        cuts.push_back(0);
        reverse(cuts.begin(),cuts.end());
        
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        
        return solve(cuts,n,1,cuts.size()-2,dp);
    }
};