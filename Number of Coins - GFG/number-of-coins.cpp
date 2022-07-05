// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int deno[], int n, int value) 
	{ 
	    // Your code goes here
	    
	    vector<int> dp(value+1,1e8);
	    dp[0]=0;
    
        
        for(int i=0;i<value+1;i++)
        {
            vector<int> v(n,1e8);
            for(int j=0;j<n;j++)
            {
                if(deno[j]<=value && i-deno[j]>=0)
                {
                    v[j]=dp[i-deno[j]]+1;
                }
            }
            int mini=*min_element(v.begin(),v.end());
            if(mini>=1e8)
               continue;
            dp[i]=mini;
        }
        
        if(dp[value]==1e8)
           return -1;
        return dp[value];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends