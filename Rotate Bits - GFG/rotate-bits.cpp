//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            d=d%16;
            
            if(d==0)
            {
                return {n,n};
            }
            
            int maxlimit=(1<<16)-1;
            
            int x=((n<<d)|(n>>(16-d)))&maxlimit;
            int y=((n>>d)|(n<<(16-d)))&maxlimit;
            
            return {x,y};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends