class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        unordered_map<int,int> mp;
        
        while(nums[0]<0)
        {
           nums[0]+=k;    
        }
        
        
        nums[0]=nums[0]%k;
        
        mp[nums[0]]++;
        
        for(int i=1;i<n;i++)
        {
            nums[i]=(nums[i]+nums[i-1])%k;
            if(nums[i]<0)
                nums[i]=abs(nums[i]+k);
            
            mp[nums[i]]++;
        }
        
        int ans=0;
        
        for(auto &it:mp)
        {
            if(it.first==0)
                ans+=it.second;
            
            ans+=(it.second*(it.second-1))/2;
        }
        
        return ans;
        
    }
};