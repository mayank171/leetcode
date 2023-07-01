//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:

    int solve(vector<int> &arr,int n,int k,int xorr,int ind,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(xorr==k)
            {
                return 1;
            }
            return 0;
        }
        
        if(dp[xorr][ind]!=-1)
           return dp[xorr][ind];
        
        xorr^=arr[ind];
        int x=solve(arr,n,k,xorr,ind+1,dp);
        xorr^=arr[ind];
        int y=solve(arr,n,k,xorr,ind+1,dp);
        return dp[xorr][ind]= x+y;
    }
    
    int subsetXOR(vector<int> arr, int N, int K) {
        
        vector<int> temp;
        int ct=0;
        int flag=0;
        vector<vector<int>> dp(1000,vector<int>(1000,-1));
        return solve(arr,N,K,0,0,dp);
        
      //  return ct;
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
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends