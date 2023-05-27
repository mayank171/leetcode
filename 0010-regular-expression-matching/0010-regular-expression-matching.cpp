class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n1=s.length();
        int n2=p.length();
        vector<vector<int>> dp(n2+1,vector<int> (n1+1,0));
        
        for(int i=0;i<n2+1;i++)
        {
            for(int j=0;j<n1+1;j++)
            {
                //cout<<i<<" "<<j<<endl;
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                }
                else if(i==0)
                {
                    dp[i][j]=0;
                }
                else if(j==0)
                {
                    if(p[i-1]=='*')
                        dp[i][j]=(i-2>=0)?dp[i-2][j]:0;
                    else
                        dp[i][j]=0;
                }
                else
                {
                    if(p[i-1]==s[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[i-1]=='.')
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[i-1]=='*')
                    {
                        int x=dp[i-2][j];
                        char prev=p[i-2];
                        if(prev=='.' || prev==s[j-1])
                        {
                            dp[i][j]=x|dp[i][j-1];
                        }
                        else
                        {
                            dp[i][j]=x;
                        }    
                    
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
            }
        }
        
        return dp[n2][n1];
    }
};