//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size();
        int m=costs[0].size();
        
        if(n>1 && m==1)
           return -1;
        
        vector<vector<int>> dp(n,vector<int> (m,0));
        multiset<int> st;
        int mini1=1e9;
        int mini2=1e9;
        for(int i=0;i<m;i++)
        {
            dp[0][i]=costs[0][i];
            st.insert(costs[0][i]);
            if(dp[0][i]<mini1)
            {
                mini2=mini1;
                mini1=dp[0][i];
            }
            else if(dp[0][i]<mini2)
            {
                mini2=dp[0][i];    
            }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=dp[i-1][j];
                if(x==mini1)
                {
                    dp[i][j]=mini2+costs[i][j];
                }
                else
                {
                    dp[i][j]=mini1+costs[i][j];
                }
            }
            
            mini1=1e9;
            mini2=1e9;
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]<mini1)
                {
                    mini2=mini1;
                    mini1=dp[i][j];
                }
                else if(dp[i][j]<mini2)
                {
                    mini2=dp[i][j];    
                }
            }
            // for(int j=0;j<m;j++)
            // {
            //     cout<<dp[i][j]<<" ";
            //     //st.insert(dp[i][j]);
            // }
            // cout<<endl;
        }
        
        // for(auto &it:dp)
        // {
        //     for(auto &it1:it)
        //     {
        //         cout<<it1<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends