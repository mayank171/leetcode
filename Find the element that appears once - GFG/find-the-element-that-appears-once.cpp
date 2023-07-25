//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int solve(int *a,int n,int mid)
    {
        if(mid-1>=0 && a[mid]!=a[mid-1])
            return true;
        return false;
    }

	int search(int A[], int N){
	    //code
	    if(A[0]!=A[1])
	       return A[0];
	       
	    if(A[N-1]!=A[N-2])
	       return A[N-1];
	       
	    
	    int low=0;
	    int high=N-1;
	    int ans=1e9;
	    
	    while(low<=high)
	    {
	        int mid=(low+high)/2;
	        
	        if(A[mid]!=A[mid-1] && A[mid]!=A[mid+1])
	        {
	            return A[mid];
	           
	        }
	        else if(mid-1>=0 && A[mid]==A[mid-1])
	        {
	            int ls=mid-low+1;
	            
	            if(ls&1)
	            {
	                high=mid-2;
	            }
	            else
	            {
	                low=mid+1;
	            }
	        }
	        else if(mid+1<=high && A[mid]==A[mid+1])
	        {
	            ans=min(ans,A[mid]);
	            int ls=mid-low;
	            
	            if(ls&1)
	            {
	                high=mid-1;
	            }
	            else
	            {
	                low=mid+2;
	            }
	        }
	    }
	    
	    
	    return -1;
	}
};








//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends