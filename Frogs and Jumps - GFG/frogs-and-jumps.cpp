//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        
        set<int> st;
        
        for(int i=1;i<=leaves;i++)
        {
            st.insert(i);
        }
        
        set<int> f;
        for(int i=0;i<N;i++)
        {
            f.insert(frogs[i]);
        }
        
        sort(frogs+0,frogs+N);
        
        for(auto &it:f)
        {
            int x=it;
            for(int i=x;i<=leaves;i+=x)
            {
                if(st.size()==0)
                   break;
                st.erase(i);
            }
            if(st.size()==0)
               break;
        }
        
        return st.size();
        
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends