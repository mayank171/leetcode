// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        // code here
        int ans=N;
        int p=log2(N);
        p++;
        for(int i=0;i<p;i++)
        {
            int x=N&(1<<i);
            if(x==0)
            {
                ans=ans|(1<<i);
            }
            //cout<<ans<<endl;
        }
        
        
        vector<int> a;
        a.push_back(ans-N);
        a.push_back(ans);
        
        return a;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends