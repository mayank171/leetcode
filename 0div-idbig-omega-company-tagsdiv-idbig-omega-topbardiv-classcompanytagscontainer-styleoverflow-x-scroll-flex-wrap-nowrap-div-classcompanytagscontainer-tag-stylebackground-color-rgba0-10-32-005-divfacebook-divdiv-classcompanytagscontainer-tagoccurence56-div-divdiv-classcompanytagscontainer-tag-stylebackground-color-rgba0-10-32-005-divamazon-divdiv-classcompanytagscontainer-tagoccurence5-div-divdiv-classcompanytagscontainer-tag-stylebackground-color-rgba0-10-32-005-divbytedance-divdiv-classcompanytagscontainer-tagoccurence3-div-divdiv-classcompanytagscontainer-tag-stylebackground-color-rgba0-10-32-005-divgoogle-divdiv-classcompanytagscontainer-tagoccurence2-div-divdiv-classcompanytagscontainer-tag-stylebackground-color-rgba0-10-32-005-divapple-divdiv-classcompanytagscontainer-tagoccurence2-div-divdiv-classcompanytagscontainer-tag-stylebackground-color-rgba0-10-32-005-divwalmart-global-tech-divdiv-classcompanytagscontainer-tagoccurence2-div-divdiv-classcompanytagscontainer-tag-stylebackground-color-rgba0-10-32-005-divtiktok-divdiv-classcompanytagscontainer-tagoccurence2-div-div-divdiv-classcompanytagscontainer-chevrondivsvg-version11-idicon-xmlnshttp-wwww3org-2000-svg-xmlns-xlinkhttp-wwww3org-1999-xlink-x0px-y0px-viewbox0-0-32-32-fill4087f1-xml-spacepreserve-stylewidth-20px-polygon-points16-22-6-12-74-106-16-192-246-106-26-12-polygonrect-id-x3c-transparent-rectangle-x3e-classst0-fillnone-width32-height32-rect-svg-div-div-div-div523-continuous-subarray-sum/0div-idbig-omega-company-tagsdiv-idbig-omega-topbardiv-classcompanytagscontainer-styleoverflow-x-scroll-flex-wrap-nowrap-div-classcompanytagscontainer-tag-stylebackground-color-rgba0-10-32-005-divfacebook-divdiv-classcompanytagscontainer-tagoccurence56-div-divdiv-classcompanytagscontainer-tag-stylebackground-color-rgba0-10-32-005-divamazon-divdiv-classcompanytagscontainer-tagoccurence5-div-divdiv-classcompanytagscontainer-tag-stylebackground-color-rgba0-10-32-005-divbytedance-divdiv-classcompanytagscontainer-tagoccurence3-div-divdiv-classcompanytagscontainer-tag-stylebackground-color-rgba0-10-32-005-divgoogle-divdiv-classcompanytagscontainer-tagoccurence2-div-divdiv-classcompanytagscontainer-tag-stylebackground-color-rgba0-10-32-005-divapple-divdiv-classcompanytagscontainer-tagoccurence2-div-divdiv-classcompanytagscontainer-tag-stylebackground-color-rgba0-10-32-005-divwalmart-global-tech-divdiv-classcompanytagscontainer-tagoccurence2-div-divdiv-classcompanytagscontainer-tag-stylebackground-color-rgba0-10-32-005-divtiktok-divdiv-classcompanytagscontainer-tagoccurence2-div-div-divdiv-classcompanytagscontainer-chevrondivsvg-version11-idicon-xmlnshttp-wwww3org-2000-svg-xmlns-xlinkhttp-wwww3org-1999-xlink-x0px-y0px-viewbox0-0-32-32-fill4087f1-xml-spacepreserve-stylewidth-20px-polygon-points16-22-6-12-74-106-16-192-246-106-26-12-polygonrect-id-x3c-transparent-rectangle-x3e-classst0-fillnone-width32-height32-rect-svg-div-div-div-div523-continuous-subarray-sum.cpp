class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
//         23 25 29 35 42
        
//         5-1
//         1-1
        
        
        
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        
        map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]%k)!=mp.end() && abs(mp[nums[i]%k]-i)>=2)
                return true;
            if(mp.find(nums[i]%k)!=mp.end())
                mp[nums[i]%k]=min(i,mp[nums[i]%k]);
            else
                mp[nums[i]%k]=i;
        }
        
        return false;
    }
};