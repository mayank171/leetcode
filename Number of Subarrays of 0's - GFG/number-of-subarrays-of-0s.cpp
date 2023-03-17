//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    
    int i=-1;
    int j=-1;
    
    long long int ans=0;
    
    while(true)
    {
        int flag1=0;
        int flag2=0;
        int one=0;
        
        while(i<n && one==0)
        {
            flag1=1;
            i++;
            if(i==n)
              break;
            if(arr[i]==1)
            {
                one=1;
            }
        }
        
        
       // cout<<i<<" "<<j<<" "<<ans<<endl;
        
        while(j<i)
        {
            flag2=1;
            ans+=(i-j-1);
            j++;
            if(arr[j]==1)
              one=0;
            if(one==0)
              break;
        }
        
    //    cout<<i<<" "<<j<<"-"<<ans<<endl;
        
        if(flag1==0 && flag2==0)
           break;
    }
    
    return ans;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends