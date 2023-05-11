//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int N, int K) {
        
        sort(A,A+N);
        
        int ans=1e9;
        
        vector<int> v;
        v.push_back(A[0]);
        
        for(int i=1;i<N;i++)
        {
            v.push_back(v.back()+A[i]);
        }
        
        int prev=0;
        for(int i=0;i<N;i++)
        {
            int ind=upper_bound(A,A+N,A[i]+K)-A;
            if(i!=0 && A[i]!=A[i-1])
            {
                prev=v[i-1];
            }
            ans=min(ans,prev+(v[N-1]-v[ind-1])-(N-ind)*(A[i]+K));
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends