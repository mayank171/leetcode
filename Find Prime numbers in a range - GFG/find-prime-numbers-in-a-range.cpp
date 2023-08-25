//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        
        vector<int> isPrime(N+1,1);
        isPrime[0]=0;
        isPrime[1]=0;
        
        int x=sqrt(N+1);
        
        for(int i=2;i<=x;i++)
        {
            if(isPrime[i]==1)
            {
                for(int j=i*i;j<N+1;j+=i)
                {
                    isPrime[j]=0;
                }
            }
        }
        
        vector<int> ans;
        
        
        
        for(int i=M;i<=N;i++)
        {
            if(isPrime[i]==1)
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends