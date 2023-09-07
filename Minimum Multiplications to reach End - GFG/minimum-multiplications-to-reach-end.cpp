//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int mod=1e5;
    
  
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,start}});
        
        vector<int> vis(1e5+10,0);
        vis[start]=1;
        
        while(!q.empty())
        {
            int moves=q.front().first;
            int ind=q.front().second.first;
            int val=q.front().second.second;
            q.pop();
            
            if(val==end)
            {
                return moves;
            }
            
            if(ind==n)
               continue;
               
            for(int i=ind;i<n;i++)
            {
                int x=(val*1ll*arr[i])%mod;
                if(vis[x]==0)
                {
                    vis[x]=1;
                    q.push({moves+1,{i,x}});
                }
            }
        }
        
        return -1;
    }
};























//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends