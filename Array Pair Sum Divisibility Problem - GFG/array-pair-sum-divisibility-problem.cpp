//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]%k]++;
        }
        
        // for(auto &it:mp)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        for(auto &it:mp)
        {
            
            if(it.first==0)
            {
                if(it.second&1)
                   return false;
                continue;
            }
            
            int x=it.second;
            if(mp.find(k-it.first)==mp.end())
               return false;
            int y=mp[k-it.first];
            //cout<<it.first<<"-"<<x<<k-it.first<<"->"<<" "<<y<<endl;
            if(y!=x)
               return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends