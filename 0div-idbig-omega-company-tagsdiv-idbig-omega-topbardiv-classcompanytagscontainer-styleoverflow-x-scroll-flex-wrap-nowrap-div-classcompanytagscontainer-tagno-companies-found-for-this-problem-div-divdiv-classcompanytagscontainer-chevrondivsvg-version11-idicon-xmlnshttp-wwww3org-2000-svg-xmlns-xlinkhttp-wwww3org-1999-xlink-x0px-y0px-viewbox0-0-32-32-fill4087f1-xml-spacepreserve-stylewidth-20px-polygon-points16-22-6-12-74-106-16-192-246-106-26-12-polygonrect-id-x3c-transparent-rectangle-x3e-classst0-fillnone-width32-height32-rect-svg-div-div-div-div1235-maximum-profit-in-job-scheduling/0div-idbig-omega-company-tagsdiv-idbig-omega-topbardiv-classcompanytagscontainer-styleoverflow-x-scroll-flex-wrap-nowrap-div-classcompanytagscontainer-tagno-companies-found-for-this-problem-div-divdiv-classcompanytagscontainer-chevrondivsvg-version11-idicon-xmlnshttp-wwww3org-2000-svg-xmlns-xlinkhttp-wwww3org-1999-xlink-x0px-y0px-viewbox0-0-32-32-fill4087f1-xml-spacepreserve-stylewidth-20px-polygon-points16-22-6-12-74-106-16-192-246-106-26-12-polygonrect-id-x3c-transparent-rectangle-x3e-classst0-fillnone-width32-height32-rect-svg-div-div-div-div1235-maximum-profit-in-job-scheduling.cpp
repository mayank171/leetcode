class Solution {
public:
    
    int solve(vector<int> &start,vector<int> &end,vector<int> &prof,int ind,int n,vector<int> &dp)
    {
        if(ind==n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int ind1=lower_bound(start.begin(),start.end(),end[ind])-start.begin();
        int take=prof[ind]+solve(start,end,prof,ind1,n,dp);
        int nottake=0+solve(start,end,prof,ind+1,n,dp);
        
        return dp[ind]=max(take,nottake);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<pair<int,pair<int,int>>> vp;
        
        
        int n=startTime.size();
        
        for(int i=0;i<startTime.size();i++)
        {
            vp.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        
        sort(vp.begin(),vp.end());
        
        for(int i=0;i<n;i++)
        {
            startTime[i]=vp[i].first;
            endTime[i]=vp[i].second.first;
            profit[i]=vp[i].second.second;
        }
        
        vector<int> dp(n,-1);
        
        return solve(startTime,endTime,profit,0,n,dp);
    }
};