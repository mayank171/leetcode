//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr,arr+n);
    	
    	long long maxi1=arr[n-1];
    	long long maxi2=arr[n-2];
    	long long mini1=arr[0];
    	long long mini2=arr[1];
    	
    	long long ans1=maxi1*maxi2*arr[n-3];
    	long long ans2=mini1*mini2*arr[2];
    	long long ans3=mini1*mini2*arr[n-1];
    	
    	long long maxi=max<long long>(ans1,max<long long>(ans2,ans3));
    	
    	return maxi;
    	
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends