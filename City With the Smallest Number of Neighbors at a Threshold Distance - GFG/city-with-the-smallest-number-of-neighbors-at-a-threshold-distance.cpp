//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) 
    {
        vector<vector<int>> dp(n,vector<int> (n,1e9));
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            dp[u][v]=d;
            dp[v][u]=d;
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dp[i][k]+dp[k][j]<dp[i][j])
                    {
                        dp[i][j]=dp[i][k]+dp[k][j];
                    }
                }
            }
        }
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]!=0 && dp[i][j]!=1e9 && dp[i][j]<=distanceThreshold)
                {
                    ct++;
                }
            }
            mp[i]=ct;
        }
        
        int mini=1e9;
        for(auto &it:mp)
        {
            if(it.second<mini)
            {
                mini=it.second;
            }
            
       //     cout<<it.first<<" "<<it.second<<endl;
        }
        
        int ans=0;
        for(auto &it:mp)
        {
            if(it.second==mini)
            {
                ans=it.first;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends