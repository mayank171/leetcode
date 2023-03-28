//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    // long long solve(int *a,int *b,int n,int x,int y,int ind,vector<long long> &dp)
    // {
    //     if(ind==n)
    //     {
    //         return 0;
    //     }
        
    //     if(dp[ind]!=-1)
    //       return dp[ind];
        
    //     long long ct1=0;
    //     long long ct2=0;
        
    //     if(x)
    //       ct1=a[ind]+solve(a,b,n,x-1,y,ind+1,dp);
    //     if(y)
    //       ct2=b[ind]+solve(a,b,n,x,y-1,ind+1,dp);
        
    //     return dp[ind]=max<long long>(ct1,ct2);
    // }
    
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        float x=abs((float)a.first-(float)a.second);
        float y=abs((float)b.first-(float)b.second);
        
        
        if(x==y)
        {
            if(a.second>=b.second)
               return true;
            return false;
        }
        else if(x<y)
        {
            return true;
        }
        
        return false;
    }
  
    long long maxTip(int a[], int b[], int n, int x, int y) {
        
        // vector<long long> dp(n,-1);
        // return solve(a,b,n,x,y,0,dp);
        vector<pair<int,int>> vp;
        
        for(int i=0;i<n;i++)
        {
            vp.push_back({a[i],b[i]});
        }
        
        sort(vp.rbegin(),vp.rend(),comp);
        
        // for(auto &it:vp)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(vp[i].first>vp[i].second)
            {
                if(x)
                {
                    ans+=vp[i].first;
                    x--;
                }
                else
                {
                    ans+=vp[i].second;
                    y--;
                }
            }
            else
            {
                if(y)
                {
                    ans+=vp[i].second;
                    y--;
                }
                else
                {
                    ans+=vp[i].first;
                    x--;
                }
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
        int n, x, y;
        cin >> n >> x >> y;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution obj;
        auto ans = obj.maxTip(a, b, n, x, y);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends