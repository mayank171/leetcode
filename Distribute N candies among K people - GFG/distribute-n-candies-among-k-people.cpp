//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<long long> distributeCandies(int N, int k) {
        
        long long i=1;
        long long pos=0;
        vector<long long> ans(k);
        
        
        while(N)
        {
             if(N<i)
             {
                ans[pos]+=N;
                break;  
             }
             else
             {
                ans[pos]+=i;
             }
             if(N-i<0)
             {
                 ans[(pos+1)%k]+=i;
                 break;
             }
             N-=i;
             i++;
             pos=(pos+1)%k;
             
             //cout<<i<<" "<<N<<" "<<pos<<endl;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends