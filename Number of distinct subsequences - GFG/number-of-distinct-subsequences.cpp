//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
    int mod=1e9+7;
    
    int binExp(int a ,int b)
    {
        int ans=1;
        while(b)
        {
            if(b&1)
            {
                ans=(ans*1ll*a)%mod;
            }
            b>>=1;
            a=(a*1ll*a)%mod;
        }
        
        return ans;
    }
    
	int distinctSubsequences(string s)
	{
	    
	    int n=s.length();
	  //  int mod=1e9+7;
	    
	    map<char,int> mp;
	    
	    vector<int> dp(n+1,0);
	    dp[0]=1;
	    
	    for(int i=1;i<n+1;i++)
	    {
	        dp[i]=(dp[i-1]*1ll*2)%mod;
	        if(mp.find(s[i-1])!=mp.end())
	        {
	            int j=mp[s[i-1]];
	            dp[i]=(dp[i]-dp[j-1]+mod)%mod;
	        }
	        mp[s[i-1]]=i;
	    }
	    
	    
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends