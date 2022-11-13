//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    void solve(int x,vector<int> &v)
    {
        if(x>1e7)
           return;
        
        int p=x%10;
        
        if(p<9)
        {
            v.push_back(x*10+(p+1));
            solve(x*10+(p+1),v);
        }
        
        if(p>0)
        {
            v.push_back(x*10+(p-1));
            solve(x*10+(p-1),v);
        }
    }

    int steppingNumbers(int n, int m)
    {
        
        vector<int> v;
        v.push_back(0);
        
        for(int i=1;i<=9;i++)
        {
            v.push_back(i);
            solve(i,v);
        }
        
        int ans=0;
        int size=v.size();
        
        for(int i=0;i<size;i++)
        {
            if(v[i]>=n && v[i]<=m)
               ans++;
        }
        
        return ans;
        
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