//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int n){
        // code here 
        if(n==0)
          return 0;
        int x=0;
        int y=1;
        int mod=1e9+7;
        
        for(int i=1;i<=n;i++)
        {
            int p=x;
            x=(2*1ll*p+y)%mod;
            y=(3*1ll*p)%mod;
        }
        
        return y;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends