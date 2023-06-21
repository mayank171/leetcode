//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalizeArray(int N, int k, int A[]){
        
        sort(A,A+N);
        
        int p;
        if(N&1)
           p=N/2;
        else
           p=N/2-1;
           
        int mod=1e9+7;
        
        int ans=0;
        for(int i=0;i<N;i++)
        {
            int x=abs(A[i]-A[p]);
            if(x%k!=0)
               return -1;
            ans=(ans+(x/k))%mod;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, k;
        cin>>N>>k;
        int A[N];
        for(int i = 0; i < N; i++)
            cin>>A[i];
            
        Solution ob;
        cout<<ob.equalizeArray(N, k, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends