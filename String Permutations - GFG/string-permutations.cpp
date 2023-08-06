//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    void solve(string &s,vector<string> &ans,string &temp,int n,int ind,map<char,int> &mp,set<int> &st)
    {
        if(temp.size()==n)
        {
            map<char,int> mp3;
            for(auto &it:s)
            {
                mp3[it]++;
            }
            
            int flag=0;
            for(auto &it:mp3)
            {
                if(mp[it.first]!=it.second)
                   return ;
            }
            
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())
            {
                temp+=s[i];
                mp[s[i]]++;
                st.insert(i);
                solve(s,ans,temp,n,i,mp,st);
                temp.pop_back();
                mp[s[i]]--;
                if(mp[s[i]]==0)
                   mp.erase(s[i]);
                st.erase(i);
            }
            
        }
    }
    
    vector<string> permutation(string S)
    {
        map<char,int> mp;
        int n=S.length();
        
        for(int i=0;i<n;i++)
        {
            mp[S[i]]++;
        }
        
        vector<string> ans;
        string temp="";
        map<char,int> mp2;
        set<int> st;
        solve(S,ans,temp,n,0,mp2,st);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends