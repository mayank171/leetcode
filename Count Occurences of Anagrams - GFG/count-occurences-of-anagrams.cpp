//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    
	    int n=txt.length();
	    
	    unordered_map<char,int> mp;
	    
	    for(int i=0;i<pat.length();i++)
	    {
	        mp[pat[i]]++;
	    }
	    
	    int ans=0;
	    int l=pat.length();
	    int ct=0;
	    unordered_map<char,int> mp1;
	    
	    for(int i=0;i<l;i++)
	    {
	       mp1[txt[i]]++;
	    }
	    
	    int flag=1;
	    for(auto &it:mp)
	    {
	        if(mp1[it.first]!=it.second)
	        {
	            flag=0;
	            break;
	        }
	    }
	    
	    if(flag==1)
	    {
	        ans++;
	    }
	    
	    for(int i=l;i<n;i++)
	    {
	        mp1[txt[i-l]]--;
	        if(mp1[txt[i-l]]==0)
	           mp1.erase(txt[i-l]);
	           
	        mp1[txt[i]]++;
	        
	        int flag=1;
    	    for(auto &it:mp)
    	    {
    	        if(mp1[it.first]!=it.second)
    	        {
    	            flag=0;
    	            break;
    	        }
    	    }
    	    
    	    if(flag==1)
    	    {
    	        ans++;
    	    }
	    }
	    
	    return ans;
	}

};







//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends