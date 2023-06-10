//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:

	int nthStair(int n){
		    
        vector<int> dp(n+1,0);
        int mod=1e9+7;
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
           dp[i]=(dp[i-2]+1)%mod;    
        }
        
        return dp[n];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends