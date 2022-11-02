//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	
	int mod=1e9+7;
	
	int solve(int n,int m,vector<int> &dp)
	{
	    if(n<0)
	      return 0;
	    if(n==0 || n==1)
	      return 1;
	      
	    if(dp[n]!=-1)
	       return dp[n];
	    
	    int l=solve(n-1,m,dp);
	    int r=solve(n-m,m,dp);
	    
	    return dp[n]=(l+r)%mod;
	}
	
	int countWays(int n, int m)
	{
	    if(n<m)
	       return 1;
	   
	       
	    vector<int> dp(n+1,-1);
	    return solve(n,m,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends