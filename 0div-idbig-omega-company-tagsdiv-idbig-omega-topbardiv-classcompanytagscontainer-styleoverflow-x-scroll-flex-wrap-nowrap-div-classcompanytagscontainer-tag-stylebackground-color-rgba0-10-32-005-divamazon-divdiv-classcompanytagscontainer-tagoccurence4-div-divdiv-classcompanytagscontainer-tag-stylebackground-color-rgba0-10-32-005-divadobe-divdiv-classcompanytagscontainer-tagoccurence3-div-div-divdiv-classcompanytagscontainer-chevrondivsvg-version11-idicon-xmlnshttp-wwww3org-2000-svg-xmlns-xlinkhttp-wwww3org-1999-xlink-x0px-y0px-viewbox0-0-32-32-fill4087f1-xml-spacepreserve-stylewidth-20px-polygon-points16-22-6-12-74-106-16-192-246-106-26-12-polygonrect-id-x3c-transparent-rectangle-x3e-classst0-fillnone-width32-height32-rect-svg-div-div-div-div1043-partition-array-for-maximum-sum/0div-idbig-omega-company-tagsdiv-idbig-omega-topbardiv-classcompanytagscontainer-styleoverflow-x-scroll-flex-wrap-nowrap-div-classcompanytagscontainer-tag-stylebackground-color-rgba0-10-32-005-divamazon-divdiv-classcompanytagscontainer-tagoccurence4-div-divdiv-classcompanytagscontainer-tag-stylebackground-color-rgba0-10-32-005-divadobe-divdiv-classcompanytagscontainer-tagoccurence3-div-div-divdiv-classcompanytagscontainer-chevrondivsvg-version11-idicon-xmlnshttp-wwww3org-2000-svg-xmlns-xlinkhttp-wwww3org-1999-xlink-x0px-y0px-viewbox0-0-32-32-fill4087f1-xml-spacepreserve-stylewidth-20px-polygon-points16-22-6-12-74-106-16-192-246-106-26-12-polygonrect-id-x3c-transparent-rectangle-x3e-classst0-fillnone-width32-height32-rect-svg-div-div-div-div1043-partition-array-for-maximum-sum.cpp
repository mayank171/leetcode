class Solution {
public:
    
    int solve(int n,int ind,map<pair<int,int>,int> &mp,int k, vector<int> &dp)
    {
        if(ind>=n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int take=0;
        for(int i=ind;i<n;i++)
        {
            if(i-ind+1<=k)
            {
                take=max(take,mp[{ind,i}]*(i-ind+1)+solve(n,i+1,mp,k,dp)); 
            }
               
        }
        
        return dp[ind]=take;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        map<pair<int,int>,int> mp;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            int maxi=0;
            for(int j=i;j<n;j++)
            {
                maxi=max(maxi,arr[j]);
                mp[{i,j}]=maxi;
            }
        }
        
        vector<int> dp(n,-1);
        return solve(n,0,mp,k,dp);
    }
};