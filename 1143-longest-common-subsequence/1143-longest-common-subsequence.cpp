class Solution {
private:
    int check(string text1,string text2,vector<vector<int>> &dp,int ind1,int ind2)
    {
        if(ind1<0 || ind2<0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
            
        if(text1[ind1]==text2[ind2])
        {
            return dp[ind1][ind2]=1+check(text1,text2,dp,ind1-1,ind2-1);
        }
        return dp[ind1][ind2]=max(check(text1,text2,dp,ind1-1,ind2),check(text1,text2,dp,ind1,ind2-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int ind1=text1.length();
        int ind2=text2.length();
        
        
        vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,0));
        
        //return check(text1,text2,dp,ind1-1,ind2-1);
        
        
        for(int i=1;i<ind1+1;i++)
        {
            for(int j=1;j<ind2+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    int x=dp[i-1][j];
                    int y=dp[i][j-1];
                    dp[i][j]=max(x,y);
                }
            }
            
        }
        
        // for(int i=0;i<ind1+1;i++)
        // {
        //     for(int j=0;j<ind2+1;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[ind1][ind2];
        
        
    }
};