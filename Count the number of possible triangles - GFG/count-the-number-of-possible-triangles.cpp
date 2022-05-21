// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr,arr+n);
        
        int ct=0;
        for(int i=2;i<n;i++)
        {
            int l=0;
            int r=i-1;
            
            while(l<=r)
            {
                if(arr[l]+arr[r]>arr[i])
                {
                    ct+=r-l;
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        
        return ct;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends