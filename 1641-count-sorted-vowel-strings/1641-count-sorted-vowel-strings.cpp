class Solution {
public:
    int countVowelStrings(int n) {
     
        vector<vector<int>> dp(5,vector<int>(n+1,0));
        
        int sum=1;
        
        for(int j=1;j<n+1;j++)
        {
            dp[0][j]=sum;
            for(int i=1;i<5;i++)
            {
                dp[i][j]=dp[i-1][j]-dp[i-1][j-1];
            }
            
            sum=0;
            
            for(int i=0;i<5;i++)
            {
                sum+=dp[i][j];
            }
            
        }
        
        return sum;
        
    }
};