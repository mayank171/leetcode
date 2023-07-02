//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    int blackBox(int arr[],int n,int k,long long mid)
    {
        int ct=1;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]+sum>mid)
            {
                ct++;
                sum=0;
            }
            sum+=arr[i];
        }
        
        if(ct>k)
           return 0;
        return 1;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        long long low=0;
        long long high=0;
        
        for(int i=0;i<n;i++)
        {
            low=max<long long>(low,arr[i]);
            high+=arr[i];
        }
        
        long long ans=high;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            
            int kk=blackBox(arr,n,k,mid);
            
            if(kk)
            {
                ans=min<long long>(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends