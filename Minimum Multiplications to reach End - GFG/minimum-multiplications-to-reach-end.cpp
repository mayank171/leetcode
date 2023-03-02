//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod=1e5;
    int solve(vector<int> &arr,int n,int start,int end,int ind)
    {
        cout<<start<<endl;
          
        if(start==end)
           return 0;
           
        if(ind>=n)
           return 1e8;
           
        
        int p=(start*arr[ind])%mod;
        if(p>end)
          return 1e8;
        int take=1+solve(arr,n,p,end,ind);
        int nottake=solve(arr,n,start,end,ind+1);
        return min(take,nottake);
    }
  
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
       // return solve(arr,n,start,end,0);
        queue<int> q;
        q.push(start%mod);
        vector<int> vis(1e5,-1);
        vis[start]=0;
        int ans=-1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            
            if(x==end)
            {
                return ans=vis[x];
            }
            
            for(int i=0;i<n;i++)
            {
                int p=(x*arr[i])%mod;
                if(vis[p]==-1)
                {
                   q.push(p);
                   vis[p]=vis[x]+1;    
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