class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n=nums.size();
        
        map<int,int> mp;
        mp[0]=1;
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]-goal)!=mp.end())
            {
                ans+=mp[nums[i]-goal];
            }
            mp[nums[i]]++;
        }
        
        return ans;
    }
};