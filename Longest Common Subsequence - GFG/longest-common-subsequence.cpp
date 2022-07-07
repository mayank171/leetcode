// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
    int helper(vector<vector<int>> &dp,string &s1,int ind1,string &s2,int ind2)
    {
        if(ind1<0 || ind2<0)
           return 0;
           
        if(dp[ind1][ind2]!=-1)
           return dp[ind1][ind2];
           
        if(s1[ind1]==s2[ind2])
        {
            return dp[ind1][ind2]=1+helper(dp,s1,ind1-1,s2,ind2-1);
        }
        return dp[ind1][ind2]=max(helper(dp,s1,ind1-1,s2,ind2),helper(dp,s1,ind1,s2,ind2-1));
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        // vector<vector<int>> dp(x,vector<int>(y,-1));
        
        // return helper(dp,s1,x-1,s2,y-1);
        
        vector<int> front(y+1,0);
        
        for(int i=1;i<x+1;i++)
        {
            vector<int> cur(y+1,0);
            for(int j=1;j<y+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    cur[j]=1+front[j-1];
                }
                else
                {
                    int p=front[j];
                    int q=cur[j-1];
                    cur[j]=max(p,q);
                }
            }
            front=cur;
        }
        
        return front[y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends