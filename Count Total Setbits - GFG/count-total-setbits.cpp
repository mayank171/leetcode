//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int n)
    {
        if(n==1)
          return 1;
        if(n==0)
          return 0;
          
        int x=log2(n);
        return x*pow(2,x-1)+(n-pow(2,x)+1)+solve(n-pow(2,x));
    }

    int countBits(int N){
        
        
        
        return solve(N);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends