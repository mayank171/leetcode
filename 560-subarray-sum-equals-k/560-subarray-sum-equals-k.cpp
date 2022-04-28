class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(n==1)
        {
            if(nums[0]==k)
                return 1;
        
        }
        
        unordered_map<int,int> mp;
        
        mp[0]++;
        
        int ans=0;
        
        
        mp[nums[0]]++;
        
        if(nums[0]==k)
            ans++;
        
        
        for(int i=1;i<n;i++)
        {
            nums[i]=(nums[i]+nums[i-1]);
            
            if(mp.find(nums[i]-k)!=mp.end())
                ans+=mp[nums[i]-k];
            
            
            mp[nums[i]]++;
        }
        
        
        return ans;
        
        
    }
};