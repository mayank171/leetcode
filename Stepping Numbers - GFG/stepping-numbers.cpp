//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    void solve(int dig,vector<int> &ans)
    {
        if(dig>1e7)
           return ;
        
        int p=dig%10;
        
        if(p>0)
        {
            int x=dig*10+(p-1);
            ans.push_back(x);
            solve(x,ans);
        }
        
        if(p<9)
        {
            
            int y=dig*10+(p+1);
            ans.push_back(y);
            solve(y,ans);
        
        }
    }

    int steppingNumbers(int n, int m)
    {
        vector<int> ans;
        ans.push_back(0);
        
        for(int i=1;i<=9;i++)
        {
           ans.push_back(i);
           solve(i,ans);
        }
        
        int ct=0;
        
        for(auto &it:ans)
        {
            if(it>=n && it<=m)
               ct++;
        }
        
        return ct;
        
    }
};


//{ Driver Code Starts.

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        Solution obj;
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends