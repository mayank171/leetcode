class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        vector<int> dp(n,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0)
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        
        for(auto &it:nums)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        for(auto &it:dp)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        int maxind=max_element(dp.begin(),dp.end())-dp.begin();
        vector<int> ans;
        ans.push_back(nums[maxind]);
        int val=dp[maxind];
        int val1=nums[maxind];
        
        for(int i=maxind-1;i>=0;i--)
        {
            if(dp[i]==val-1 && (nums[i]%val1==0 || val1%nums[i]==0))
            {
                ans.push_back(nums[i]);
                val--;
                val1=nums[i];
            }
        }
        
        return ans;
        
    }
};