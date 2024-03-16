class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        
        map<int,int> mp;
        mp[0]=-1;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }
        
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(0-nums[i])!=mp.end())
            {
                ans=max(ans,i-mp[0-nums[i]]);
            }
            
            if(mp.find(0-nums[i])==mp.end())
            {
                mp[0-nums[i]]=i;
            }
        }
        
        return ans;
    }
};