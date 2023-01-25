//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int ispalindrome(string &temp)
    {
        int l=temp.size();
        
        for(int i=0,j=l-1;i<j;i++,j--)
        {
            if(temp[i]!=temp[j])
               return 0;
        }
        return 1;
    }

    int solve(string &str,int n,int ind,string &temp,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(ispalindrome(temp)==1)
               return 0;
            return 1e7;
        }
        
        if(dp[ind][temp.size()]<1e7)
           return dp[ind][temp.size()];
        
        int pick=1e7;
        int notpick=1e7;
        
        temp+=str[ind];
        pick=solve(str,n,ind+1,temp,dp);
        temp.pop_back();
        
        if(ispalindrome(temp)==1)
        {
           string temp1="";
           temp1+=str[ind];
           notpick=1+solve(str,n,ind+1,temp1,dp); 
        }
           
        
        return dp[ind][temp.size()]=min(pick,notpick);
    }


    int palindromicPartition(string str)
    {
        int n=str.length();
        string temp="";
        vector<vector<int>> dp(n,vector<int>(n+1,1e7));
        return solve(str,n,0,temp,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends