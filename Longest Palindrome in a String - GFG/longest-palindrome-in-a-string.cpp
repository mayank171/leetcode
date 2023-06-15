//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        
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
                       dp[i][j]=2;
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]!=0)
                    {
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                }
            }
        }
        
        int ii=-1;
        int jj=-1;
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]>maxi)
                {
                    ii=i;
                    jj=j;
                    maxi=dp[i][j];
                }
            }
        }
        
        // map<int,string> mp;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(dp[i][j]==maxi)
        //         {
                    
        //         }
        //     }
        // }
        
        string ans="";
        
        for(int j=jj;j>=ii;j--)
        {
            ans+=s[j];
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends