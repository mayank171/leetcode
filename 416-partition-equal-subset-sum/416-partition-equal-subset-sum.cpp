class Solution {
public:
    bool check(vector<vector<int>> &dp,vector<int> &nums,int ind,int sum)
    {
        if(ind==0)
        {
            if(nums[ind]==sum)
                return true;
            return false;
        }
        
        if(sum==nums[ind])
        {
            return true;
        }
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        bool take=false;
        bool notTake=false;
        
        if(nums[ind]<=sum)
            take=check(dp,nums,ind-1,sum-nums[ind]);
        notTake=check(dp,nums,ind-1,sum);
        
        return dp[ind][sum]=take|notTake;
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum&1)
            return false;
        
        sum=sum/2;
        
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        
        return check(dp,nums,n-1,sum);
        
    }
};