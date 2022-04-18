// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])==mp.end())
            {
                mp[arr[i]]=i+1;
            }
            else
            {
                if(mp[arr[i]]<0)
                  continue;
                else
                  mp[arr[i]]*=-1;
            }
        }
        
        int maxi=INT_MIN;
        
        for(auto &it:mp)
        {
            if(it.second>maxi && it.second<0)
            {
                maxi=it.second;
            }
           // cout<<it.first<<" "<<it.second<<endl;
        }
        
        //cout<<maxi<<endl;
        
        
        if(maxi==INT_MIN)
        return -1;
        
        return -1*maxi;
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
  // } Driver Code Ends