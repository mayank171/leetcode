class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]%k<0)
            {
                nums[i]=k+nums[i]%k;
            }
            else
            {
                nums[i]=nums[i]%k;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        
        map<int,int> mp;
        mp[0]=1;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]%k)!=mp.end())
            {
                ans+=mp[nums[i]%k];
            }
            mp[nums[i]%k]++;
        }
        
        return ans;
    }
};