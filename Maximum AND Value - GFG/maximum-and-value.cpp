//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int ct=0;
            int p=ans|(1<<i);
            for(int j=0;j<N;j++)
            {
                
                int x=p&arr[j];
                if(x==p)
                   ct++;
                if(ct==2)
                   break;
            }
            
            if(ct==2)
            {
                ans=(ans|(1<<i));
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends