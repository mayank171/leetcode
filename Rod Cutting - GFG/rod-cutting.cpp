// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int check(vector<vector<int>> &dp,int *price,vector<int> &length,int len,int ind)
    {
        if(ind==0)
        {
            return price[ind]*len;
        }
        
        if(dp[ind][len]!=-1)
           return dp[ind][len];
        
        int take=-1e8;
        if(length[ind]<=len)
           take=price[ind]+check(dp,price,length,len-length[ind],ind);
        int notTake=check(dp,price,length,len,ind-1);
        
        return dp[ind][len]=max(take,notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int> length(n);
        for(int i=0;i<n;i++)
        {
            length[i]=i+1;
        }
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        return check(dp,price,length,n,n-1);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends