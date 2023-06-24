class Solution {
public:
    
    int solve(vector<int> &rods,int n,int ind,int sum,vector<unordered_map<int,int>> &dp)
    {
        if(ind==n)
        {
            if(sum==0)
            {
                return 0;
            }
            
            return -1e5;
        }
        
        if(dp[ind].find(sum)!=dp[ind].end())
            return dp[ind][sum];
        
        int leave=solve(rods,n,ind+1,sum,dp);
        int add=rods[ind]+solve(rods,n,ind+1,sum+rods[ind],dp);
        int sub=solve(rods,n,ind+1,sum-rods[ind],dp);
        
        return dp[ind][sum]= max(leave,max(add,sub));
    }
    
    int tallestBillboard(vector<int>& rods) {
        
        int n=rods.size();
        
        vector<unordered_map<int,int>> dp(n);
        return solve(rods,n,0,0,dp);
        
    }
};