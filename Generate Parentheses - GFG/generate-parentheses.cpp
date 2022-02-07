// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    private:
    
    void check(int o,int c,string &s,vector<string> &ans,int n)
    {
        if(o+c==2*n)
        {
            ans.push_back(s);
            return ;
        }
        
        if(o<c)
           return ;
           
        if(o<n)
        {
            s.push_back('(');
            check(o+1,c,s,ans,n);
            s.pop_back();
        }
        
        if(c<n)
        {
            s.push_back(')');
            check(o,c+1,s,ans,n);
            s.pop_back();
        }
        
        
    }
    
    public:
    vector<string> AllParenthesis(int n) 
    {
        int c=0;
        int o=0;
        
        string s="";
        
        vector<string> ans;
        
        check(o,c,s,ans,n);
        
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends