// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int low=0;
        int high=n-1;
        
        while(low<high)
        {
            if(low+1==high)
                break;
            
            int mid=(low+high)/2;
            
            if(arr[mid]<arr[high])
            {
                high=mid;
            }
            else
            {
                low=mid;
            }
        }
        
        return min(arr[low],arr[high]);
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends