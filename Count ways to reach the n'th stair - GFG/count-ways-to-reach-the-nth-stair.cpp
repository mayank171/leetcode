// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    int mod=1e9+7;
    int check(int n,vector<int> &dp,int sum)
    {
        if(sum==0)
        {
            return dp[0]=1;
        }
        
        if(dp[sum]!=-1)
            return dp[sum];
           
        int l=0;
        int r=0;
        if(sum-1>=0)
           l=check(n,dp,sum-1);
        if(sum-2>=0)
           r=check(n,dp,sum-2);
        return dp[sum]=(l+r)%mod;
    }
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        return check(n,dp,n);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends