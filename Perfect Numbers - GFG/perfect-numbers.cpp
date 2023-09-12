//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long n) {
        
        set<long long> st;
        
        long long nn=n;
        
        for(long long i=2;i*1ll*i<=n;i++)
        {
            long long x=n;
            if(x%i==0)
            {
                st.insert(i);
                st.insert(x/i);
            }
        }
        
        st.insert(1);
        
        if(n>1)
           st.insert(n);
           
        long long sum=0;
        
        for(auto &it:st)
        {
        //    cout<<it<<" ";
            if(it!=nn)
            {
                sum+=it;
            }
        }
        //cout<<endl;
        
        if(sum==nn)
           return 1;
        return 0;
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
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends