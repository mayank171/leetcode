//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
      int mod=1e9+7;
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        int sum1=accumulate(arr,arr+n,0);
        if(sum>sum1)
          return 0;
        
        vector<int> front(sum+1,0);
        if(arr[0]==0) 
           front[0]=2;
        else
          front[0]=1;
        if(arr[0]!=0 && arr[0]<=sum)
          front[arr[0]]=1;
          
        for(int i=1;i<n;i++)
        {
            vector<int> cur(sum+1,2);
            for(int j=0;j<sum+1;j++)
            {
                int pick=0;
                if(arr[i]<=j)
                   pick=pick+front[j-arr[i]];
                int notpick=front[j];
                cur[j]=(pick+notpick)%mod;
            }
            front=cur;
        }
        
        return front[sum];
	}
	  
};



//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends