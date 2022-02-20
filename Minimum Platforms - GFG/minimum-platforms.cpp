// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
   /* static bool comp(pair<int,int>a, pair<int,int> b)
    {
        return a.first>b.first;
    }*/
    
    
    int findPlatform(int arr[], int dep[], int n)
    {
        
        int maxi=1;
        int ct=1;
        
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int p=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]<=dep[p])
            {
                ct++;
                maxi=max(maxi,ct);
            }
            else
            {
                p++;
            }
        }
        
        return maxi;
            
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends