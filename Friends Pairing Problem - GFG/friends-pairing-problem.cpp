//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mod=1e9+7;
    
    int solve(int n,vector<int> &dp)
    {
        if(n==0)
        {
            return 1;
        }
        
        if(n<0)
        {
            return 0;
        }
        
        if(dp[n]!=-1)
          return dp[n];
        
        int x=solve(n-1,dp);
        int y=((n-1)*1ll*solve(n-2,dp))%mod;
        
        return dp[n]=(x+y)%mod;
    }

    int countFriendsPairings(int n) 
    { 
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends