//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        
        vector<int> isPrime(n+1,0);
        isPrime[0]=0;
        isPrime[1]=1;
        
        for(int i=2;i<n+1;i++)
        {
            if(isPrime[i]==0)
            {
                isPrime[i]=i;
                for(int j=i*2;j<n+1;j+=i)
                {
                    if(isPrime[j]==0)
                       isPrime[j]=i;
                }
            }
        }
        
        return isPrime;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends