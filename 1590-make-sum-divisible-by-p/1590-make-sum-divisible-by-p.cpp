class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        long long sum=0;
        int n=nums.size();
    
        vector<long long> v;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];   
            v.push_back(nums[i]);
        }
    
        
        int rem=sum%p;
        if(rem==0)
            return 0;
        if(p>sum)
            return -1;
        
        map<int,int> mp;
        mp[0]=-1;
        int ans=1e9;
        
        for(int i=1;i<n;i++)
        {
            v[i]+=v[i-1];
        }
        
        for(int i=0;i<n;i++)
        {
            int r=v[i]%p;
            cout<<r<<endl;
            r=r-rem;
            
            if(r<0)
            {
                r+=p;
            }
            
            if(mp.find(r)!=mp.end())
            {
                if(i==n-1 && r==0 && mp[0]==-1)
                {
                    
                }
                else
                {
                    ans=min(ans,i-mp[r]);
                }
            }
            
            mp[v[i]%p]=i;
        }
        
        if(ans==1e9)
            return -1;
        return ans;
        
    }
};