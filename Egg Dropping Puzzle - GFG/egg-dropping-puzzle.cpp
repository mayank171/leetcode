//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int n,int k,vector<vector<int>> &dp)
    {
        if(n==0)
           return 0;
        if(k==0)
           return 0;
        if(n==1)
           return k;
        if(k==1)
           return 1;
           
        if(dp[n][k]!=-1)
           return dp[n][k];
        
        int eb=0;
        int es=0;
        int ans=1e8;
        for(int i=1;i<=k;i++)
        {
            eb=solve(n-1,i-1,dp);
            es=solve(n,k-i,dp);
        
            int x=max(eb,es);
            
            ans=min(ans,x+1);
        }
        
        return dp[n][k]=ans;
    }
    
    int eggDrop(int n, int k) 
    {
        
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends