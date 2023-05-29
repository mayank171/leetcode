//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> dict, string pattern) {
        
        map<string,vector<string>> mp;
        int size=dict.size();
        
        for(int i=0;i<size;i++)
        {
            string x="";
            int l=dict[i].size();
            for(int j=0;j<dict[i].size();j++)
            {
                if(dict[i][j]>='A' && dict[i][j]<='Z')
                {
                    x+=dict[i][j];
                }
            }
            mp[x].push_back(dict[i]);
        }
        
        vector<string> ans;
        
        for(auto &it:mp)
        {
            string x=it.first;
            int flag=0;
            
            for(int i=0;i<pattern.size();i++)
            {
                if(i>=x.length())
                {
                    flag=1;
                    break;
                }
                if(pattern[i]!=x[i])
                {
                    flag=1;
                    break;
                }
            }
            
            if(flag==0)
            {
                for(int i=0;i<it.second.size();i++)
                {
                    ans.push_back(it.second[i]);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        if(ans.size()==0)
           return {"-1"};
           
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends