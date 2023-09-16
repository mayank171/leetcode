//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        vector<long long> dp(n+1,0);
        dp[0]=1;
        int mod=1e9+7;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(i-j>=0)
                {
                    dp[i]=(dp[i]+dp[i-j])%mod;
                }
            }
        }
        
        return dp[n];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends