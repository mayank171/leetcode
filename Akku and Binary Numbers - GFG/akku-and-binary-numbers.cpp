//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    
    long long solve(long long l, long long r){
        
        int p;
        
        if(r>l)
           p=log2l(r);
        else
           p=log2l(l);
           
       // cout<<p<<endl;
        
        long long val=0;
        for(int i=0;i<p+1;i++)
        {
            for(int j=i+1;j<p+1;j++)
            {
                for(int k=j+1;k<p+1;k++)
                {
                    long long x=0;
                    x=(x|(1l<<i));
                    x=(x|(1l<<j));
                    x=(x|(1l<<k));
                    if(x>=l && x<=r)
                    {
           //             cout<<x<<endl;
                        val++;
                    }
                }
            }
        }
        
        return val;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends