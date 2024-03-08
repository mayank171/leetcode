class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        map<int,int> mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        int maxi=0;
        for(auto &it:mp)
        {
            maxi=max(maxi,it.second);
        }
        
        int ans=0;
        for(auto &it:mp)
        {
            if(it.second==maxi)
                ans+=it.second;
        }
        
        return ans;
    }
};