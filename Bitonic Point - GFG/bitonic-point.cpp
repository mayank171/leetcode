//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    
	    int low=0;
	    int high=n-1;
	    
	    int ans=high;
	    
	    while(high-low>=3)
	    {
	        int m1=low+(high-low)/3;
	        int m2=high-(high-low)/3;
	        
	        int val1=arr[m1];
	        int val2=arr[m2];
	        
	        if(val1>val2)
	        {
	            high=m2;
	        }
	        else
	        {
	            low=m1;
	        }
	    }
	    
	    return max(arr[low],max(arr[low+1],arr[low+2]));
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends