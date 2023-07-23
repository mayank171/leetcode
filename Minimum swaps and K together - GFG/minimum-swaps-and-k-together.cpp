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
        // Complet the function
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
               ct++;
        }
        
        int c=0;
        int ans=1e5;
        for(int i=0;i<ct;i++)
        {
            if(arr[i]>k)
               c++;
        }
        
        ans=min(ans,c);
        //cout<<ans<<endl;
        
        for(int i=ct;i<n;i++)
        {
            if(arr[i-ct]>k)
               c--;
            if(arr[i]>k)
               c++;
            
            ans=min(ans,c);
        }
        
        return ans;
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