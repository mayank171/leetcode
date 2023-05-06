class Solution {
public:
    int mod=1e9+7;
    
    int binExp(int a,int b)
    {
        int ans=1;
        while(b)
        {
            if(b&1)
            {
                ans=(ans*1ll*a)%mod;
            }
            a=(a*1ll*a)%mod;
            b>>=1;
        }
        
        return ans;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int i=0;
        int j=n-1;
        
        int ans=0;
        while(i<=j)
        {
            if(nums[i]+nums[j]<=target)
            {
                ans=(ans+binExp(2,j-(i+1)+1))%mod;
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return ans;
        
    }
};