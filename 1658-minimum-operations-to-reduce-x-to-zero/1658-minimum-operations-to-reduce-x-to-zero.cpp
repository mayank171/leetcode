class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        sum-=x;
        cout<<sum<<endl;
        
        if(sum==0)
            return n;
        
        vector<long long> v;
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            v.push_back(v.back()+nums[i]);
        }
        
        int ans=1e9;
        map<long long,int> mp;
        mp[0]=-1;
        
        for(int i=0;i<n;i++)
        {
            long long p=v[i]-sum;
           // cout<<p<<endl;
            if(mp.find(p)!=mp.end())
            {
                int ind=mp[p];
                //cout<<"ind"<<ind<<endl;
                int left=0;
                int right=0;
                if(ind==-1)
                  left=0;
                else
                  left=ind+1;
                
                right=n-i-1;
                
                ans=min(ans,left+right);
            }
            mp[v[i]]=i;
        }
        
        if(ans==1e9)
            return -1;
        return ans;
        
    }
};