class Solution {
public:
    
    int solve(vector<vector<int>> &vp,int n,int ind,int k,vector<vector<int>> &dp)
    {
        if(k<=0)
            return 0;
        
        if(ind>=n)
            return 0;
        
        if(dp[ind][k]!=-1)
            return dp[ind][k];
    
        int sum=0;
        int sum1=solve(vp,n,ind+1,k,dp);
        int cur=0;
        for(int j=0;j<vp[ind].size() && j<k;j++)
        {
            cur+=vp[ind][j];
            sum=max(sum,solve(vp,n,ind+1,k-j-1,dp)+cur);
        }
        
        return dp[ind][k]=max(sum1,sum);
    
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n=piles.size();
        vector<stack<int>> vp;
        
        vector<vector<int>> dp(1001,vector<int>(2001,-1));
        for(int i=0;i<n;i++)
        {
            stack<int> ste;
            for(int j=piles[i].size()-1;j>=0;j--)
            {
                ste.push(piles[i][j]);
            }
            vp.push_back(ste);
        }
        
        //return 0;
        return solve(piles,n,0,k,dp);
    }
};