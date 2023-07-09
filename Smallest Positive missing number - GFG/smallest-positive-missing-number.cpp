//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=0)
            {
                arr[i]=0;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
               continue;
            int pos=abs(arr[i]);
            pos--;
            if(pos>=0 && pos<n)
            {
                if(arr[pos]>0)
                   arr[pos]*=-1;
                else if(arr[pos]==0)
                   arr[pos]=-1*(n+1);
            }
        }
        
        // for(int i=0;i<n;i++)
        //   cout<<arr[i]<<" ";
        // cout<<endl;
        
        int ans=n+1;
        for(int i=1;i<=n;i++)
        {
            int pos=i-1;
            if(arr[pos]>=0)
            {
                ans=pos+1;
                break;
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends