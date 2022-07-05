class Solution {
public:
    int change(int value, vector<int>& deno) {
        
    vector<int> dp(value+1,0);
    
    dp[0]=1;
        
    int n=deno.size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<value+1;j++)
        {
            if(j-deno[i]>=0)
            {
                dp[j]+=dp[j-deno[i]];
            }
        }
    }
    
    return dp[value];
        
    }
};