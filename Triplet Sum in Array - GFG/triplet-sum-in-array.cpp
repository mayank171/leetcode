// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        sort(arr,arr+n);
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            int target=X-arr[i];
            
            while(j<k)
            {
                if(arr[j]+arr[k]==target)
                {
                    return 1;
                }
                else if(arr[j]+arr[k]>target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        
        return 0;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends