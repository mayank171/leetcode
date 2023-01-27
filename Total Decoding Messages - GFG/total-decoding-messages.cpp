//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int mod=1e9+7;
	    int solve(string &str,int n,int ind,int num,vector<int> &dp)
	    {
	       // cout<<num<<endl;
	        if(ind==n)
	        {
	            return 1;
	        }
	        
	        if(dp[ind]!=-1)
	           return dp[ind];
	        
	        int ct1=0;
	        int ct2=0;
	        
	        int p=num;
	        num=(str[ind]-'0');
	        if(num>=1 && num<=9)
	            ct1=solve(str,n,ind+1,num,dp);
	        if(ind+1<n)
	        {
	            num=num*10+(str[ind+1]-'0');
	            if(num>=10 && num<=26)
	               ct2=solve(str,n,ind+2,num,dp);
	        }
	        
	        return dp[ind]=(ct1+ct2)%mod;
	    }
	
		int CountWays(string str){
		    
		    int n=str.length();
		    int num=0;
		    vector<int> dp(n,-1);
		    
		     solve(str,n,0,num,dp);
		    
		  //  for(auto &it:dp)
		  //  {
		  //      cout<<it<<" ";
		  //  }
		  //  cout<<endl;
		    
		    return dp[0];
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends