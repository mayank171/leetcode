//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int  countPS(string str)
    {
       int mod=1e9+7;
       int n=str.length();
       
       vector<vector<int>> dp(n,vector<int>(n,0));
       
       for(int gap=0;gap<n;gap++)
       {
           for(int i=0,j=gap;j<n;i++,j++)
           {
            //   cout<<i<<" "<<j<<endl;
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
                       dp[i][j]=((dp[i+1][j]+dp[i][j-1])%mod-dp[i+1][j-1]+mod)%mod;
                   }
                   else
                   {
                       dp[i][j]=((dp[i+1][j]+dp[i][j-1])%mod+1)%mod;
                   }
               }
           }
       }
       
    //   for(auto &it:dp)
    //   {
    //       for(auto &it1:it)
    //           cout<<it1<<" ";
    //       cout<<endl;
    //   }
       
    //   cout<<"cdcd";
       
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