//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        
        map<char,int> mp;
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        int ct=0;
        
        for(auto &it:mp)
        {
            ct+=it.second-1;
        }
        
        string ans=s;
        
        int i=0;
        int j=n-1;
        int flag=1;
        
        while(i<j)
        {
            if(flag==1)
            {
                while(i<j && mp[s[i]]==1)
                {
                    i++;
                }
                
                if(i>=j)
                   break;
                   
                mp[s[i]]--;
                ans[i]='.';
                i++;
                flag*=-1;
            }
            else if(flag==-1)
            {
                while(i<j && mp[s[j]]==1)
                {
                    j--;
                }
                
                if(i>=j)
                   break;
                   
                mp[s[j]]--;
                ans[j]='.';
                j--;
                flag*=-1;
            }
        }
        
        s.clear();
        
        for(int i=0;i<n;i++)
        {
            if(ans[i]!='.')
               s+=ans[i];
        }
        
        if(ct&1)
        {
            reverse(s.begin(),s.end());
            return s;
        }
        else
        {
            return s;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends