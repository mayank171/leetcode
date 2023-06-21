class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        long long sum=0;
        int n=nums.size();
        
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({nums[i],cost[i]});
        }
        
        sort(vp.begin(),vp.end());
        
        for(int i=0;i<n;i++)
        {
            sum+=cost[i];
        }
        
        sum/=2;
        
        long long  cur=0;
        int ind;
        
        for(int i=0;i<n;i++)
        {
            cur+=vp[i].second;
            if(cur>sum)
            {
              //  cout<<nums[i]<<endl;
                ind=vp[i].first;
                break;
            }
        }
        
       // cout<<ind<<endl;
        
        long long res=0;
        for(int i=0;i<n;i++)
        {
            int p=abs(vp[i].first-ind);
            res+=(p*1ll*vp[i].second);
        }
        
        return res;
    }
};