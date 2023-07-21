//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        
        int ans=0;
        
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
               ct++;
        }
        
        int mini=1e9;
        int ctr=0;
        for(int i=0;i<ct;i++)
        {
            if(arr[i]>k)
               ctr++;
        }
        
        mini=min(mini,ctr);
        
        for(int i=ct;i<n;i++)
        {
            if(arr[i-ct]>k)
               ctr--;
            if(arr[i]>k)
               ctr++;
               
            mini=min(mini,ctr);
        }
        
        return mini;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends