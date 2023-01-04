//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int n, vector<int> &arr) {
        
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;j++,i++)
            {
                int maxi=0;
                for(int k=i;k<=j;k++)
                {
                    int left=(i==k)?0:dp[i][k-1];
                    int right=(j==k)?0:dp[k+1][j];
                    int val=(i==0?1:arr[i-1])*arr[k]*(j==n-1?1:arr[j+1]);
                    val+=left+right;
                    maxi=max(maxi,val);
                }
                
                dp[i][j]=maxi;
            }
        }
        
        return dp[0][n-1];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends