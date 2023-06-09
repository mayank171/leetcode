class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> freq(1e4+10,0);
        
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        
        int ans=0;
        vector<int> dp(1e4+10,0);
        dp[1]=0+1*freq[1];
        
        for(int i=2;i<1e4+10;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+(i*freq[i]));
        }
        
        return dp[1e4+9];
        
    }
};