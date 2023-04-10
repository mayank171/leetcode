//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[1]-a[0]>b[1]-b[0])
        {
            return true;
        }
        
        return false;
    }
  
    int maxIntersections(vector<vector<int>> lines, int N) {
        
        map<int,int> mp;
        
        for(int i=0;i<N;i++)
        {
            int start=lines[i][0];
            int end=lines[i][1];
            
            mp[start]++;
            mp[end+1]--;
        }
        
        int maxi=0;
        int ans=0;
        
        for(auto &it:mp)
        {
            ans+=it.second;
            maxi=max(maxi,ans);
        }
        
        return maxi;
        
    }
};
























//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends