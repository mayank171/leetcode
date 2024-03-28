class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int i=-1;
        int j=-1;
        
        int ans=0;
        map<int,int> mp;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1)
            {
                flag1=1;
                i++;
                mp[nums[i]]++;
                if(mp[nums[i]]>k)
                    break;
                else
                    ans=max(ans,i-j);
            }
            
            while(j<i)
            {
                flag2=1;
                j++;
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                    mp.erase(nums[j]);
                if(mp[nums[j]]==k)
                    break;
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};