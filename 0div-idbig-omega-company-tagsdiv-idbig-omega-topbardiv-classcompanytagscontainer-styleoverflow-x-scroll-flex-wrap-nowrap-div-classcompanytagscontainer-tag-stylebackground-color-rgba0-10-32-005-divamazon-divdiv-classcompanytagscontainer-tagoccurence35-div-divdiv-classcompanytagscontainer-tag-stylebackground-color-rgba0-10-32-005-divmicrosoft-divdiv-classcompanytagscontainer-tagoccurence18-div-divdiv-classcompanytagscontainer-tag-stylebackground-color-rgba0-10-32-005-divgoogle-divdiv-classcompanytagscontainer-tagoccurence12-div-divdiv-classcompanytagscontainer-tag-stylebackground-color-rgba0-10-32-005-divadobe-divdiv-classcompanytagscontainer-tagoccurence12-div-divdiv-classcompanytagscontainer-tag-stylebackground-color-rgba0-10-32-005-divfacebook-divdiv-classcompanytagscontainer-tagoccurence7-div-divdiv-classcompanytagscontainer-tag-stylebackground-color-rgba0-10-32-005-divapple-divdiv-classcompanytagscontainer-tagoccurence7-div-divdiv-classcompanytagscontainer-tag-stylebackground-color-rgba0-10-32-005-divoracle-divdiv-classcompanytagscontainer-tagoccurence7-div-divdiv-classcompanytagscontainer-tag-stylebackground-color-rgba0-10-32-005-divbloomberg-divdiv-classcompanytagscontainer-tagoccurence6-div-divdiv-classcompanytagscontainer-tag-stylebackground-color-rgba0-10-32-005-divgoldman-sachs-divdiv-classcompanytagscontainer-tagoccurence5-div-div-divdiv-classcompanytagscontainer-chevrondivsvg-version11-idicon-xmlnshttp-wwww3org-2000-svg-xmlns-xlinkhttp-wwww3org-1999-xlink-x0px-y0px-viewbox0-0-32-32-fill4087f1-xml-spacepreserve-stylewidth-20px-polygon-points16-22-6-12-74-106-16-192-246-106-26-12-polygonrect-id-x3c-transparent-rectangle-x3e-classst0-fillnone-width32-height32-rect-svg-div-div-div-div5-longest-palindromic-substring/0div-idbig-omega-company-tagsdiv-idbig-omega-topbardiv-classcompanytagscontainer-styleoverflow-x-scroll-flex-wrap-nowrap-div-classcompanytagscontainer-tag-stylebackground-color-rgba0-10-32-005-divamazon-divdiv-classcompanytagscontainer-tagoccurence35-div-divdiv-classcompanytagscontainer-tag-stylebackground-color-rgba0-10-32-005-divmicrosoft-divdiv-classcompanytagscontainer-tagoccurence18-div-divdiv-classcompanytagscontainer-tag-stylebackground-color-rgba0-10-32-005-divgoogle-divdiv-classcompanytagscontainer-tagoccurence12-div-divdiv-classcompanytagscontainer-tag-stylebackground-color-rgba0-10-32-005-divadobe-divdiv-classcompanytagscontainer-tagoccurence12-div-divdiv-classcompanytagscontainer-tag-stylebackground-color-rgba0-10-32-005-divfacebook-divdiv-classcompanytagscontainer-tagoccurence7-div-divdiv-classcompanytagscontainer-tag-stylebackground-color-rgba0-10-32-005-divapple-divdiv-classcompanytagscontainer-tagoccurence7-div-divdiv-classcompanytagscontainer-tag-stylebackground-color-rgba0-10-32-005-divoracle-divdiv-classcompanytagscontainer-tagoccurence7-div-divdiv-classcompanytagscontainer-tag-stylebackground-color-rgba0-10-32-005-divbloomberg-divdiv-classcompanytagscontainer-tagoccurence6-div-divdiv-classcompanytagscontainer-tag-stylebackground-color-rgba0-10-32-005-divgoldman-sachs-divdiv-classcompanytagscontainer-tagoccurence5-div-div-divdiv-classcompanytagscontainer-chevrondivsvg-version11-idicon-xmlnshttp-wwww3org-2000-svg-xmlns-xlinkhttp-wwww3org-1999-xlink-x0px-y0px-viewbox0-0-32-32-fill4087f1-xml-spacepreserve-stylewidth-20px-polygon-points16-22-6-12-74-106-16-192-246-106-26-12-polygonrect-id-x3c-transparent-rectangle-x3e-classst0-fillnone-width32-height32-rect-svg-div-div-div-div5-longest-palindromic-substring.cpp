class Solution {
public:
    
    
    string longestPalindrome(string s) {
        
        int n=s.length();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(gap==0)
                {
                    dp[i][j]=1;
                }
                else if(gap==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=2;
                    }
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]!=0)
                    {
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                }
            }
        }
        
        int maxi=0;
        int ii,jj;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]>maxi)
                {
                    maxi=dp[i][j];
                    ii=i;
                    jj=j;
                }
            //    cout<<dp[i][j]<<" ";
            }
         //   cout<<endl;
        }
        
        string ans="";
        
        for(int k=jj;k>=ii;k--)
        {
            ans+=s[k];
        }
        
        return ans;
    }
};