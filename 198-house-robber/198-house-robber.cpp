class Solution {
private:
    
    int check(vector<int> &nums,vector<int> &dp,int ind)
    {
        if(ind==0)
        {
            return dp[ind]=nums[ind];
        }
        
        if(ind<0)
        {
            return 0;
        }
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int sum1=nums[ind]+check(nums,dp,ind-2);
        int sum2=0+check(nums,dp,ind-1);
        
        return dp[ind]=max(sum1,sum2);
    }
    
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> dp(n,-1);
        
        int ind=n-1;
        
        check(nums,dp,ind);
        
        return dp[n-1];
        
    }
};