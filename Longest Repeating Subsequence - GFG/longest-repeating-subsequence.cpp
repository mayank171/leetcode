//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	    int solve(string &str1,string &str2,int ind1,int ind2,int flag,vector<vector<int>> &dp)
	    {
	        if(ind1<0 || ind2<0)
	        {
	            return 0;
	        }
	        
	        if(dp[ind1][ind2]!=-1)
	        {
	            return dp[ind1][ind2];
	        }
	        
	        if(str1[ind1]==str2[ind2])
	        {
	            if(ind1==ind2)
	            {
	                return dp[ind1][ind2]=max(solve(str1,str2,ind1-1,ind2,flag,dp),solve(str1,str2,ind1,ind2-1,flag,dp));
	            }
	            return dp[ind1][ind2]=1+solve(str1,str2,ind1-1,ind2-1,flag,dp);
	        }
	        else
	        {
	            return dp[ind1][ind2]=max(solve(str1,str2,ind1-1,ind2,flag,dp),solve(str1,str2,ind1,ind2-1,flag,dp));
	        }
	        
	    }
	
		int LongestRepeatingSubsequence(string s){
		    
		    
		    int l=s.length();
		    vector<vector<int>> dp(l,vector<int>(l,-1));
		    return solve(s,s,l-1,l-1,0,dp);
		    
		   
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