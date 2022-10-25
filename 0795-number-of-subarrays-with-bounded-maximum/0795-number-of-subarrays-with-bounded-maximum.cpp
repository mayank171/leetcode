class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int n=nums.size();
        
        int ans=0;
        int ctless=0;
        int ct=0;
        
        vector<int> vp;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<left)
            {
                ct++;
                ctless++;
            }
            else if(nums[i]>=left && nums[i]<=right)
            {
                if(ctless>0)
                {
                    vp.push_back(ctless);
                    ctless=0;
                }
                ct++;
               
            }
            else if(nums[i]>right)
            {
                if(ctless>0)
                {
                    vp.push_back(ctless);
                    ctless=0;
                }
                ans+=(ct*1ll*(ct+1))/2;
                ct=0;
            }
        }
        
        if(ct>0)
        {
            ans+=(ct*1ll*(ct+1))/2;    
        }
        if(ctless>0)
        {
            vp.push_back(ctless);
        }
        
        for(int i=0;i<vp.size();i++)
        {
            ans-=(vp[i]*1ll*(vp[i]+1))/2;
        }
        
        return ans;
        
    }
};