//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        
        bool ans=true;
        map<int,int> mp;
        
        for(int i=0;i<N;i++)
        {
            if(bills[i]==5)
            {
                mp[5]++;
            }
            else if(bills[i]==10)
            {
                if(mp[5]>0)
                {
                    mp[5]--;
                    mp[10]++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                
                if(mp[5]>=1 && mp[10]>=1)
                {
                    mp[5]--;
                    mp[10]--;
                    mp[20]++;
                }
                else if(mp[5]>=3)
                {
                    mp[5]-=3;
                    mp[20]++;
                }
                else
                    return false;
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
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends