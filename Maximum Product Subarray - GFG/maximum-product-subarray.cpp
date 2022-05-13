// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long max_left=1;
	    long long maxi1=INT_MIN;
	    long long max_right=1;
	    long long maxi2=INT_MIN;
	    
	    for(int i=0;i<n;i++)
	    {
	        max_left=arr[i]*max_left;
	        if(max_left==0)
	          max_left=1;
	        maxi1=max(maxi1,max_left);
	    }
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        max_right=arr[i]*max_right;
	        if(max_right==0)
	          max_right=1;
	        maxi2=max(maxi2,max_right);
	    }
	    
	    return max(maxi1,maxi2);
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends