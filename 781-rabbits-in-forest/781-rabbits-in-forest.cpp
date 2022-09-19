class Solution {
public:
    int numRabbits(vector<int>& v) {
        
        
        int n=v.size();
        
        map<int,vector<pair<int,int>>> mp;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(v[i])==mp.end())
            {
                mp[v[i]].push_back({v[i]+1,1});
            }
            else
            {
                if(mp[v[i]].back().first==mp[v[i]].back().second)
                {
                    mp[v[i]].push_back({v[i]+1,1});
                }
                else
                {
                    mp[v[i]].back().second=mp[v[i]].back().second+1;
                }
            }
        }
        
        int ans=0;
            
        for(auto &it:mp)
        {
            for(auto &it1:it.second)
            {
                ans+=it1.first;
            }
        }
        
        return ans;
        
    }
};