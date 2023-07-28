//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        
        // vector<int> digits;
        // while(X)
        // {
        //     digits.push_back(X%10);
        //     x/=10;
        // }
        
        // reverse(digits.begin(),digits.end());
        
        queue<long long> q;
        
        for(int i=1;i<=9;i++)
        {
            q.push(i);
        }
        
        long long ans=0;
        while(!q.empty())
        {
            long long n=q.front();
            q.pop();
            
            
            if(n>X)
               continue;
            
            ans=max<long long>(ans,n);
               
            for(int i=0;i<=9;i++)
            {
                long long p=n;
                if(abs(p%10-i)==1)
                {
                    p=p*1ll*10+i;
                    q.push(p);
                }
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends