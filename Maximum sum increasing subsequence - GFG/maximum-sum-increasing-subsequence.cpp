// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	
	
	int maxSumIS(int arr[], int n)  
	{  
	    
	   // int ans=0;
	    
	    vector<int> dp(n,0);
	    for(int i=0;i<n;i++)
	    {
	        dp[i]=arr[i];
	    }
	    
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                dp[i]=max(dp[i],arr[i]+dp[j]);
	            }
	        }
	    }
	    
	    int maxi=*max_element(dp.begin(),dp.end());
	    
	    
	    return maxi;
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	   // // Your code goes here
	   // vector<int> ans;
	    
	   // for(int i=0;i<n;i++)
	   // {
	   //     int size=ans.size();
	        
	   //     if(ans.size()==0)
	   //     {
	   //         ans.push_back(arr[i]);
	   //     }
	   //     else
	   //     {
	   //         if(arr[i]>ans[size-1])
	   //         {
	   //             ans.push_back(arr[i]);
	   //         }
	   //         else
	   //         {
	   //             int ind=upper_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
	                
	   //             if(ind==size)
	   //             {
	   //                 continue;
	   //             }
	   //             else if(ind-1>=0 && ans[ind-1]==arr[i])
	   //             {
	   //                 continue;
	   //             }
	   //             else 
	   //             {
	   //                 ans[ind]=arr[i];
	   //             }
	   //         }
	   //     }
	   // }
	    
	   // int sum=accumulate(ans.begin(),ans.end(),0);
	    
	   // return sum;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends