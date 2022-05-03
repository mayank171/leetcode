class Solution {
private:
    
//      int check(vector<int> &cost,int n,vector<int> &dp)
//      {
//          if(n==1)
//          {
//              return dp[n]=cost[1];
//          }
         
//          if(n==0)
//          {
//              return dp[n]=cost[0];
//          }
         
//          if(dp[n]!=-1)
//          {
//              return dp[n];
//          }
         
//          return dp[n]=min(check(cost,n-1,dp),check(cost,n-2,dp))+cost[n];
         
//      }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
//         int n=cost.size();
        
//         cost.push_back(0);
        
//         vector<int> dp(n+1,-1);
        
//         check(cost,n,dp);
        
//         for(auto &it:dp)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         return min(dp[n-1],dp[n-2]);
        
        int n=cost.size();
        
        if(n==2)
        {
            return min(cost[0],cost[1]);
        }
        
        vector<int> dp(n,0);
        
        dp[0]=cost[0];
        
        for(int i=1;i<n;i++)
        {
            if(i-2<0)
                dp[i]=cost[i]+min(dp[i-1],0);
            else
                dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        
        // for(auto &it:dp)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        return min(dp[n-2],dp[n-1]);
        
    }
};