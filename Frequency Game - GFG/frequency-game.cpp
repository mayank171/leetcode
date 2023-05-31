//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto &it:mp)
        {
            pq.push({it.first,it.second});
        }
        
        int maxi=-1;
        int ct=1e9;
        while(!pq.empty())
        {
            int val=pq.top().first;
            int c=pq.top().second;
           // cout<<val<<" "<<c<<endl;
            pq.pop();
            
            if(maxi<val && c<=ct)
            {
                maxi=val;
                ct=c;
            }
        }
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends