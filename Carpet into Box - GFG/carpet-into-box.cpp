//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int solve(int A,int B,int C,int D)
    {
        if(A<=C && B<=D)
        {
            return 0;
        }
        if(A<=D && B<=C)
        {
            return 0;
        }
        
        if(A>C)
        {
            return 1+solve(A/2,B,C,D);
        }
        
        if(B>D)
        {
            return 1+solve(A,B/2,C,D);
        }
        
    }
    
    int carpetBox(int A, int B, int C, int D){
        
        int ans1=solve(A,B,C,D);
        int ans2=solve(A,B,D,C);
        
       // cout<<ans1<<" "<<ans2<<endl;
        
        return min(ans1,ans2);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends