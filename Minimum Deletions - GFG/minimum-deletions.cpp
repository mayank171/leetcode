//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    int solve(string &s1,string &s2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
           return 0;
           
        if(dp[ind1][ind2]!=-1)
           return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2])
        {
            return dp[ind1][ind2]=1+solve(s1,s2,ind1-1,ind2-1,dp);
        }
        else
        {
            return dp[ind1][ind2]=max(solve(s1,s2,ind1-1,ind2,dp),solve(s1,s2,ind1,ind2-1,dp));
        }
    }
  
    int minimumNumberOfDeletions(string S) { 
        
        string s1=S;
        reverse(S.begin(),S.end());
        string s2=S;
        int n=S.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return n-solve(s1,s2,n-1,n-1,dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends