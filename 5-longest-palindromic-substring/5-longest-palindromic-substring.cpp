class Solution {
public:
    string longestPalindrome(string s) {
        
        int l=s.length();
        
        vector<vector<int>> dp(l,vector<int>(l,0));
        
        for(int gap=0;gap<l;gap++)
        {
            for(int i=0,j=gap;j<l;i++,j++)
            {
                if(gap==0)
                {
                    dp[i][j]=1;
                }
                else if(gap==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                else 
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                    }
                    else
                        dp[i][j]=0;
                }
            }
        }
        
//         for(int i=0;i<l;i++)
//         {
//             for(int j=0;j<l;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        int start=-1;
        int end=-1;
        int maxi=0;
        for(int i=0;i<l;i++)
        {
            for(int j=i;j<l;j++)
            {
                if(dp[i][j]==1)
                {
                    if(j-i>=maxi)
                    {
                        maxi=j-i;
                        start=i;
                        end=j;
                    }
                }
               // cout<<start<<" "<<end<<endl;
            }
            
        }
        
        string ans=s.substr(start,end-start+1);
        return ans;
        
    }
};