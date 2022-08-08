class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> ct(n,1);
    
        for(int i=1;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<i;j++)
            {
                
                if(arr[i]>arr[j] && dp[i]==dp[j]+1)
                {
                    ct[i]+=ct[j];
                }
                else if(arr[i]>arr[j] && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    ct[i]=ct[j];
                }
            }
        }
    
        int maxi=0;
        int ind=0;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]>maxi)
            {
                maxi=dp[i];
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                ans+=ct[i];
            }
        }
        
        return ans;
        
    }
};