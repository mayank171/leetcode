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
    
    
    int countDistinct(vector<int>& nums, int k, int p) {

        set<pair<int,int>> st;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int p1=1;
            int q=1;
            int sum1=0;
            int sum2=0;
            int ct=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%p==0)
                {
                    ct++;
                }
                
                if(ct>k)
                    break;
                
                sum1=(sum1+(nums[j]*1ll*p1)%mod)%mod;    
                sum2=(sum2+(nums[j]*1ll*q)%mod)%mod;    
                
                st.insert({sum1,sum2});
                p1=(p1*1ll*31)%mod;
                q=(q*1ll*37)%mod;
                
            }
        }
        
        return st.size();
    }
};