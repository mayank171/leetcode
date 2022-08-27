class Solution {
public:
    
    bool solve(vector<int>&nums,int n,int ind,vector<int> &dp)
    {
        if(ind==n)
            return true;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        if(ind+1<n)
        {
            if(nums[ind]==nums[ind+1])
            {
                if(solve(nums,n,ind+2,dp))
                    return true;
                
            }
        }
        
        if(ind+2<n)
        {
            if(nums[ind]==nums[ind+1] && nums[ind]==nums[ind+2])
            {
                if(solve(nums,n,ind+3,dp))
                    return true;
            }
            else if(nums[ind]+1==nums[ind+1] && nums[ind+1]+1==nums[ind+2])
            {
                if(solve(nums,n,ind+3,dp))
                    return true;
            }
        }
        
        return dp[ind]=false;
    }
    
    bool validPartition(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,-1);
        
        return solve(nums,n,0,dp);
        
        
    }
};