class Solution {
public:
    
    int solve(vector<vector<int>> &events,int n,int ind,int k,vector<vector<int>> &dp)
    {
        if(ind>=n || k==0)
            return 0;
        
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        
        int maxi=0;
        int i;
        for(i=ind+1;i<n;i++)
        {
            if(events[i][0]>events[ind][1])
            {
                break;
            }
        }
        
        
        return dp[ind][k]=max(events[ind][2]+solve(events,n,i,k-1,dp),0+solve(events,n,ind+1,k,dp));
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(events,n,0,k,dp);
    }
};