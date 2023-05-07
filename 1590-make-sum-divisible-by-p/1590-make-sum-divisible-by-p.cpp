class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n=nums.size();
        
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        int rem=sum%p;
        
        if(rem==0)
            return 0;
        
        if(sum<p)
            return -1;
        
        vector<long long> v;
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            v.push_back(v.back()+nums[i]);
        }
        
        map<int,int> mp;
        mp[0]=-1;
        int ans=1e9;
        
        for(int i=0;i<n;i++)
        {
            int r=v[i]%p;
            r=r-rem;
          //  cout<<r<<endl;
            
            if(r<0)
                r+=p;
            
            if(mp.find(r)!=mp.end())
            {
               // cout<<i<<" "<<mp[r]<<endl;
                if(i==n-1 && mp[r]==-1)
                {}
                else
                ans=min(ans,i-mp[r]);        
            }
            mp[v[i]%p]=i;
        }
        
        if(ans==1e9)
            return -1;
        return ans;
        
    }
};