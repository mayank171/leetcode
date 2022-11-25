//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
        
        
        int cursum1=arr[0];
        int maxsum1=arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(cursum1<0)
            {
                cursum1=0;
            }
            
            cursum1+=arr[i];
            maxsum1=max(maxsum1,cursum1);
        }
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            arr[i]=arr[i]*-1;
        }
        
        int cursum=arr[0];
        int maxsum=arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(cursum<0)
            {
                cursum=0;
            }
            
            cursum+=arr[i];
            
            maxsum=max(maxsum,cursum);
        }
        
        int minsum=-1*maxsum;
        //cout<<minsum<<endl;
        
        int ct=0;
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]*-1;
            if(arr[i]<0)
               ct++;
        }
        
        if(ct==n)
        {
            int maxi=*max_element(arr,arr+n);
            
            return maxi;
        }
        
        //cout<<maxsum1<<" "<<sum-minsum<<endl;
        
        return max(maxsum1,sum-minsum);
        
        
        
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