//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	public:
	
	int solve(int *cost,vector<int> &wts,int ind,int wt,vector<vector<int>> &dp)
    {
        if(ind<0)
        {
            if(wt==0)
              return 0;
            return 1e9;
        }
        
        if(wt==0)
           return 0;
           
        if(dp[ind][wt]!=-1)
           return dp[ind][wt];
        
        int take=1e9;
        if(wt>=wts[ind] && cost[ind]!=-1)
        {
            take=cost[ind]+min(solve(cost,wts,ind,wt-(ind+1),dp),solve(cost,wts,ind-1,wt-(ind+1),dp));
        }
        int nottake=solve(cost,wts,ind-1,wt,dp);
        
        return dp[ind][wt]=min(take,nottake);
    }
	
	int minimumCost(int cost[], int N, int W) 
	{ 
	    vector<int> wts;
	    for(int i=0;i<N;i++)
	    {
	        wts.push_back(i+1);
	    }
	    
	    vector<vector<int>> dp(N+1,vector<int> (W+1,-1));
	    
        int ans= solve(cost,wts,N-1,W,dp);
        
        if(ans==1e9)
           return -1;
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends