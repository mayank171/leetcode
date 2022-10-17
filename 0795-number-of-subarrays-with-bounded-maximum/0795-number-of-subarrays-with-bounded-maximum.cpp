class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int n=nums.size();
        
        int ans=0;
        
        int ctless=0;
        int ct=0;
        
        vector<int> v;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<left)
            {
                ctless++;
                ct++;
            }
            else if(nums[i]>=left && nums[i]<=right)
            {
                if(ctless>0)
                {
                    v.push_back(ctless);
                    ctless=0;
                }
                ct++;
            }
            else if(nums[i]>right)
            {
                ans+=(ct*1ll*(ct+1))/2;
                if(ctless>0)
                   v.push_back(ctless);
                ctless=0;
                ct=0;
            }
                
        }
        
        if(ctless>0)
            v.push_back(ctless);
        
        if(ct>0)
            ans+=(ct*1ll*(ct+1))/2;
        
        int size=v.size();
        for(int i=0;i<size;i++)
        {
            ans-=(v[i]*1ll*(v[i]+1))/2;
        }
        
        return ans;
        
    }
};