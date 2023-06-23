class Solution {
public:
    
    int solve(vector<int> &nums,int ind,int diff,int n,vector<map<int,int>> &dp)
    {
        
        if(ind-1<0)
            return 0;
        
        if(dp[ind].find(diff)!=dp[ind].end())
            return dp[ind][diff];
        
        int ans=0;
        for(int i=ind-1;i>=0;i--)
        {
            if(nums[ind]-nums[i]==diff)
            {
                ans=max(ans,1+solve(nums,i,diff,n,dp));
            }
        }
        
        return dp[ind][diff]= ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<map<int,int>> dp(n+1);
        
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 ans=max(ans,2+solve(nums,i,nums[j]-nums[i],n,dp));
//             }
//         }
        
//         return ans;
        
        
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j];
                int ct=1;
                
                if(dp[j].find(diff)!=dp[j].end())
                    ct=dp[j][diff];
                dp[i][diff]=ct+1;
                ans=max(ans,dp[i][diff]);
            }
        }
        
        return ans;
    }
};