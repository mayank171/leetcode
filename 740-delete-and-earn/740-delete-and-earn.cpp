class Solution {
public:
    int check(vector<int> &dp,int n,vector<pair<int,int>> &nums,int ind)
    {
        if(ind<0)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int take=0;
        int notTake=0;
        
        if(ind-1>=0 && nums[ind-1].first+1==nums[ind].first)
           take=nums[ind].first*nums[ind].second+check(dp,n,nums,ind-2);
        else
           take=nums[ind].first*nums[ind].second+check(dp,n,nums,ind-1);
        
        notTake=0+check(dp,n,nums,ind-1);
        
        return dp[ind]=max(take,notTake);
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        vector<pair<int,int>> vp;
        for(auto &it:mp)
        {
            int ct=it.second;
            vp.push_back({it.first,it.second});
        }
        
        int size=vp.size();
        
        vector<int> dp(n,-1);
        
        return check(dp,size,vp,size-1);
        
    }
};