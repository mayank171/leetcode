class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        map<int,vector<int>> mp;
        int n=arr.size();
        
        for(int i=1;i<n;i++)
        {
            arr[i]^=arr[i-1];
        }
        
        mp[0].push_back(-1);
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])!=mp.end())
            {
                for(auto &it:mp[arr[i]])
                {
                    ans+=(i-(it+1));
                }
            }
            mp[arr[i]].push_back(i);
        }
        
        return ans;
    }
};