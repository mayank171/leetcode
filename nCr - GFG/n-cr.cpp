//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1e9+7;
    
    int binExp(int a,int b)
    {
        int ans=1;
        while(b)
        {
            if(b&1)
            {
                ans=(ans*1ll*a)%mod;
            }
            a=(a*1ll*a)%mod;
            b=b>>1;
        }
        
        return ans;
    }
    
    vector<int> pre;
    
    int nCr(int n, int r){
        
        if(r>n)
            return 0;
            
        vector<int> temp(n+1);
        pre=temp;
        
        pre[0]=1;
        for(int i=1;i<=n;i++)
        {
            pre[i]=(i*1ll*pre[i-1])%mod;
            
        }
        
        int num=pre[n];
        int deno=(pre[n-r]*1ll*pre[r])%mod;
        
       // cout<<num<<" "<<deno<<endl;
        
        int ans=(num*1ll*(binExp(deno,mod-2)))%mod;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends