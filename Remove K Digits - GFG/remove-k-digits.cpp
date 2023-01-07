//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        
        int n=s.length();
        
        stack<char> stk;
        
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else
            {
                while(!stk.empty() && stk.top()>s[i] && k>0)
                {
                    stk.pop();
                    k--;
                }
                
                stk.push(s[i]);
            }
        }
        
        string ans="";
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        
        while(ans.size()>0 && ans.back()=='0')
        {
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        
        while(k && ans.size()>0)
        {
            ans.pop_back();
            k--;
        }
        
        if(ans.size()==0)
           return "0";
        
        return ans;
        
    }
};















//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends