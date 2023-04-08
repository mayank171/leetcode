//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        
        stack<int> stk;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(arr[i]);
            }
            else 
            {
                if(!stk.empty() && stk.top()<0 && arr[i]>=0)
                {
                    stk.pop();
                }
                else if(!stk.empty() && stk.top()>=0 && arr[i]<0)
                {
                    stk.pop();
                }
                else
                {
                    stk.push(arr[i]);
                }
            }
            
        }
        
        vector<int> ans;
        
        while(!stk.empty())
        {
            int x=stk.top();
            stk.pop();
            ans.push_back(x);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
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

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends