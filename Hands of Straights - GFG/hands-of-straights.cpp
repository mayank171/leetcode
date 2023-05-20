//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int g, vector<int> &hand) {
        
        map<int,int> mp;
        
        for(int i=0;i<N;i++)
        {
            mp[hand[i]]++;
        }
        
        while(mp.size()>0)
        {
            auto it=*mp.begin();
          //  cout<<it.first<<" "<<it.second<<endl;
            int start=it.first;
            
            for(int i=0;i<g;i++)
            {
                if(mp.find(start)==mp.end())
                   return false;
                mp[start]--;
                if(mp[start]==0)
                   mp.erase(start);
                start++;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends