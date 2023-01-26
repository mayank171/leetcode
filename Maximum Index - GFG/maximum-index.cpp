//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        
        vector<pair<int,int>> vp(n);
        vp[n-1]={arr[n-1],n-1};
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=vp[i+1].first)
            {
                vp[i].first=arr[i];
                vp[i].second=i;
            }
            else
            {
                vp[i].first=vp[i+1].first;
                vp[i].second=vp[i+1].second;
            }
        }
        
        // for(auto &it:vp)
        // {
        //     cout<<it.first<<","<<it.second<<" ";
        // }
        // cout<<endl;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=vp[i].first)
            {
              //  cout<<arr[i]<<" "<<vp[i].second<<endl;
                ans=max(ans,vp[i].second-i);
                int j=vp[i].second+1;
                while(j<n)
                {
                    if(arr[i]<=vp[j].first)
                    {
                      //  cout<<arr[i]<<" "<<vp[j].second<<endl;
                        ans=max(ans,vp[j].second-i);
                        j=vp[j].second+1;
                    }
                    else
                    {
                        break;
                    }
                }
               // break;
            }
            
            if(ans>n-i+1)
              break;
        }
        
        return ans;
        
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends