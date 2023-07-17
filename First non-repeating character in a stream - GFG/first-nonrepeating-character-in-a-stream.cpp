//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string s){
	    // Code here
	    int n=s.length();
		    
        string ans="";
        
        vector<int> freq(26,0);
        set<char> st;
        queue<char> q;
        
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            freq[ch-'a']++;
            
            if(freq[ch-'a']==1)
            {
               if(st.find(ch)==st.end())
               {
                   st.insert(ch);
                   q.push(ch);
               }
            }
            else if( freq[ch-'a']>1)
            {
               st.erase(ch);
               queue<char> q1;
               while(!q.empty())
               {
                   if(q.front()!=ch)
                      q1.push(q.front());
                   q.pop();
               }
               q=q1;
            }
               
            if(st.size()>0)
            {
                char first=q.front();
               // q.pop();
              //  st.erase(first);
                ans+=first;
            }
            else
            {
                ans+='#';
            }
        }
        
        
        return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends