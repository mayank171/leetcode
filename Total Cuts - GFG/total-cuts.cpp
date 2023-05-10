//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
       
        vector<int> large(N);
        large[0]=A[0];
        vector<int> small(N);
        small[N-1]=A[N-1];
        
        for(int i=1;i<N;i++)
        {
            large[i]=max(large[i-1],A[i]);
        }
        
        for(int i=N-2;i>=0;i--)
        {
            small[i]=min(small[i+1],A[i]);
        }
        
        int ans=0;
        
        for(int i=0;i<N-1;i++)
        {
            int x=large[i];
            int y=small[i+1];
            
            if(x+y>=K)
               ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends