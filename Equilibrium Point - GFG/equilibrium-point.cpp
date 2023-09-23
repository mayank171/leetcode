//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        if(n==1)
           return 1;
    
        //vector<long long> v1(n,0);
        long long v1[n];
        v1[0]=a[0];
        
        for(int i=1;i<n;i++)
        {
            v1[i]=v1[i-1]+a[i];
        }
        
        //vector<long long> v2(n,0);
        long long v2[n];
        v2[n-1]=a[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            v2[i]=v2[i+1]+a[i];
        }
        
        // for(auto &it:v1)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        // for(auto &it:v2)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        
        
        int ind=-1;
        
        for(int i=1;i<n-1;i++)
        {
            if(v1[i-1]==v2[i+1])
            {
                return i+1;
            }
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends