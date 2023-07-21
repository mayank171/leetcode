//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        int n=s.length();
        set<char> st;
        
        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
        }
        
        int i=-1;
        int j=-1;
        vector<int> freq(256,0);
        int ans=1e9;
        int ct=0;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            while(i<n-1)
            {
                flag1=1;
                i++;
                //mp[s[i]]++;
                freq[s[i]]++;
                if(freq[s[i]]==1)
                   ct++;
                if(ct==st.size())
                {
                    break;
                }
            }
            
            while(j<i && ct==st.size())
            {
                flag2=1;
                ans=min(ans,i-j);
                j++;
                //mp[s[j]]--;
                freq[s[j]]--;
                if(freq[s[j]]==0)
                {
                    ct--;
                }
            }
            
            if(flag1==0 && flag2==0)
               break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends