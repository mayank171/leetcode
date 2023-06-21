//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int sumOfNaturals(int n) {
        
        int mod=1e9+7;
        int p=(n*1ll*(n+1))%mod;
        
        return p/2;
        // int max=1000;
        // int sum=(max*(max+1))/2;
        // int mod=1e9+7;
        
        // if(n<max)
        // {
        //     int ans=0;
        //     for(int i=1;i<=n;i++)
        //     {
        //         ans=(ans+i)%mod;
        //     }
            
        //     return ans;
        // }
        // else
        // {
        //     int q=n/max;
        //     int ans=(q*1ll*sum)%mod;
            
        // }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends