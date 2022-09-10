class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        int mod=1e9+7;
        vector<int> sums;
        
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum=(sum+nums[j])%mod;
                sums.push_back(sum);
            }
            
        }
        
        sort(sums.begin(),sums.end());
        
        int ans=0;
        for(int i=left-1;i<right;i++)
        {
            ans=(ans+sums[i])%mod;
        }
        
        return ans;
        
    }
};