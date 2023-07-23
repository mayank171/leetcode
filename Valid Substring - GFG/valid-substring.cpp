//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int n=s.length();
        vector<int> dp(n,0);
        
        int ind=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=')')
            {
                ind=i;
                break;
            }
        }
        
        map<int,int> mp;
        int ct=0;
        mp[0]=ind-1;
        
        for(int i=ind;i<n;i++)
        {
            if(s[i]=='(')
            {
                ct++;
                mp[ct]=i;
            }
            else
            {
                if(ct-1>=0)
                {
                    ct--;
                    int ind=mp[ct];
                    dp[i]=i-ind;    
                }
                else
                {
                    mp.clear();
                    int j=i;
                    while(j<n && s[j]==')')
                       j++;
                    mp[0]=j-1;
                    i=j-1;
                }
            }
        }
        
        int ans=0;
        for(auto &it:dp)
        {
           // cout<<it<<" ";
            ans=max(ans,it);
        }
    //    cout<<endl;
        
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
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends