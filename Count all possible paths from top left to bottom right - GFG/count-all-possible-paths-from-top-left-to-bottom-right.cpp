// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    int mod=1e9+7;
  public:
    long long int numberOfPaths(int n, int m){
        // code here
        vector<vector<long long>> ans(n,vector<long long>(m,0));
        
        for(int i=0;i<m;i++)
        {
            ans[0][i]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            ans[i][0]=1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                ans[i][j]=(ans[i-1][j]+ans[i][j-1])%mod;
            }
        }
        
        return ans[n-1][m-1];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends