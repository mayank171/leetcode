//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void solve(map<char,int> &mp,int n,string &temp,vector<string> &ans)
	{
	    if(temp.size()==n)
	    {
	        ans.push_back(temp);
	        return ;
	    }
	    
	    for(auto &it:mp)
	    {
	        if(it.second>0)
	        {
	            temp+=it.first;
	            it.second--;
	            solve(mp,n,temp,ans);
	            it.second++;
	            temp.pop_back();
	        }
	    }
	}
	
    vector<string>find_permutation(string S)
	{
	    int n=S.length();
	    
	    map<char,int> mp;
	    for(int i=0;i<n;i++)
	    {
	        mp[S[i]]++;
	    }
	    
	    vector<string> ans;
	    string temp="";
	    
	    solve(mp,n,temp,ans);
	       
	    return ans;
	}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends