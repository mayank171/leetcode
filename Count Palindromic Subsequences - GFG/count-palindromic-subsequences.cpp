//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       int n=str.length();
       
       int mod=1e9+7;
       
       vector<vector<long long int>> dp(n+1,vector<long long int> (n+1,0));
       
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
                    if(str[i]==str[j])
                       dp[i][j]=3;
                    else
                       dp[i][j]=2;
               }
               else
               {
                    if(str[i]!=str[j])
                    {
                        long long int x=0;
                        x=(x+dp[i][j-1])%mod;
                        x=(x+dp[i+1][j])%mod;
                        x=(x-dp[i+1][j-1]+mod)%mod;
                        dp[i][j]=x;
                    }
                    else
                    {
                        long long int x=0;
                        x=(x+dp[i][j-1])%mod;
                        x=(x+dp[i+1][j])%mod;
                        dp[i][j]=(x+1)%mod;
                    }
               }
           }
       }
       
       return dp[0][n-1];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends