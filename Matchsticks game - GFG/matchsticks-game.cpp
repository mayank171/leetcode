//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool solve(int n,int flag)
    {
        if(n==0)
        {
            if(flag==1)
               return true;
            return false;
        }
        
        if(flag==1)
        {
            bool ans;
            for(int i=1;i<=4;i++)
            {
                if(n-i<0)
                   break;
                bool b=solve(n-i,0);
                if(b==false)
                   return false;
            }
            return true;
        }
        else
        {
            bool ans;
            for(int i=1;i<=4;i++)
            {
                if(n-i<0)
                   break;
                bool b=solve(n-i,1);
                if(b==true)
                   return true;
            }
            return false;
        }
    }
  
    int matchGame(long long N) {
        
        // int ans=-1;
        // for(int i=1;i<=4;i++)
        // {
        //     bool b=solve(N-i,1);
        //     if(b)
        //     {
        //         ans=i;
        //     }
        // }
        
        // return ans;
        
        if(N%5==0)
           return -1;
        else 
           return N%5;
    }
};

















//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends