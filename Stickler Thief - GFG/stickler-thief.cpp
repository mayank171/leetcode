//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int *arr,int n,int ind,vector<int> &dp)
    {
        if(ind>=n)
           return 0;
           
        if(dp[ind]!=-1)
           return dp[ind];
        
        int take=arr[ind]+solve(arr,n,ind+2,dp);
        int nottake=0+solve(arr,n,ind+1,dp);
        
        return dp[ind]=max(take,nottake);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n,-1);
        return solve(arr,n,0,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends