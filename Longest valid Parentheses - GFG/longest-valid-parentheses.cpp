//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        
        int n=S.length();
        
        int cur=0;
        vector<int> v;
        
        for(int i=0;i<n;i++)
        {
            if(S[i]=='(')
            {
                cur++;
                v.push_back(cur);
            }
            else if(S[i]==')')
            {
                if(cur-1<0)
                {
                    v.push_back(0);
                    cur=0;
                }
                else
                {
                    cur--;
                    v.push_back(cur);
                }
            }
        }
        
        map<int,vector<int>> mp;
        mp[0].push_back(-1);
        
        int ans=0;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            if(S[i]==')' && v[i]>=0)
            {
                int ind=mp[v[i]][mp[v[i]].size()-1];
                if(i-ind>1)
                   dp[i]=dp[ind]+(i-ind);
               // dp.push_back(i-ind);
            }
            
            if(v[i]>=0)
               mp[v[i]].push_back(i);
        }
        
        // for(auto &it:v)
        //     cout<<it<<" ";
        // cout<<endl;
        
        // for(auto &it:dp)
        //     cout<<it<<" ";
        // cout<<endl;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};


















//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends