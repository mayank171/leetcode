//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    
		    int n=A.length();
		    
		    vector<string> freq(n+1);
		    
		    string ans="";
		    map<char,int> mp;
		    
		    for(int i=0;i<n;i++)
		    {
		        mp[A[i]]++;
		        
		        freq[mp[A[i]]].push_back(A[i]);
		        
		        //freq[mp[A[i]]][A[i]-'a']=1;
		        
		        if(mp[A[i]]>1)
		           freq[mp[A[i]]-1].erase(remove(freq[mp[A[i]]-1].begin(),freq[mp[A[i]]-1].end(),A[i]),freq[mp[A[i]]-1].end());
		        
		      //  if(mp[A[i]]>1)
		      //  {
		      //      freq[mp[A[i]]-1][A[i]-'a']--;
		      //  }
		        
		       if(freq[1].size()==0)
		       {
		           ans+='#';
		       }
		       else
		       {
		           ans+=freq[1][0];
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