//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int circularSubarraySum(int arr[], int n){
    
        int maxsum=arr[0];
        int cursum1=arr[0];
        int minsum=arr[0];
        int cursum2=arr[0];
        
        int sum=accumulate(arr,arr+n,0);
        
        for(int i=1;i<n;i++)
        {
            cursum1=max(cursum1+arr[i],arr[i]);
            maxsum=max(cursum1,maxsum);
            cursum2=min(cursum2+arr[i],arr[i]);
            minsum=min(cursum2,minsum);
        }
        
       // cout<<minsum<<" "<<maxsum<<endl;
        
        if(maxsum<0)
           return maxsum;
        return max(sum-minsum,maxsum);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends