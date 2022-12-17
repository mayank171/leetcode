//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	    int solve(string &str1,string &str2,int ind1,int ind2,vector<vector<int>> &dp)
	    {
	        
	        if(ind1<0 || ind2<0)
	           return 0;
	           
	        if(dp[ind1][ind2]!=-1)
	           return dp[ind1][ind2];
	        
	        int y=0;
	        int x=0;
	        
	        if(str1[ind1]==str2[ind2])
	        {
	            if(ind1==ind2)
	            {
	                x=max(solve(str1,str2,ind1,ind2-1,dp),solve(str1,str2,ind1-1,ind2,dp));        
	            }
	            else
	            {
	                x=1+solve(str1,str2,ind1-1,ind2-1,dp);
	            }
	        }
	        else
	            y=max(solve(str1,str2,ind1-1,ind2,dp),solve(str1,str2,ind1,ind2-1,dp));
	            
	        return dp[ind1][ind2]=max(x,y);
	    }
	
		int LongestRepeatingSubsequence(string str){
		    
		    int l=str.length();
		    
		    vector<vector<int>> dp(l,vector<int>(l,-1));
		    
		    return solve(str,str,l-1,l-1,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends