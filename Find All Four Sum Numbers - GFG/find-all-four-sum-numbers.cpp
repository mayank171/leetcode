//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;
        
        int n=arr.size();
        
        map<vector<int>,int> mp;
        
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<i-1;j++)
            {
                int x=arr[j]+arr[i-1];
                int target=k-x;
                
                
                int k=i;
                int l=n-1;
                
                while(k<l)
                {
                  //  cout<<j<<" "<<i-1<<" "<<k<<" "<<l<<endl;
                    if(arr[k]+arr[l]==target)
                    {
                        vector<int> vp;
                        vp.push_back(arr[j]);
                        vp.push_back(arr[i-1]);
                        vp.push_back(arr[k]);
                        vp.push_back(arr[l]);
                        sort(vp.begin(),vp.end());
                        mp[vp]=1;
                        k++;
                        l--;
                    }
                    else if(arr[k]+arr[l]>target)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }
        
        for(auto &it:mp)
        {
            vector<int> temp;
            for(auto &it1:it.first)
            {
                temp.push_back(it1);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends