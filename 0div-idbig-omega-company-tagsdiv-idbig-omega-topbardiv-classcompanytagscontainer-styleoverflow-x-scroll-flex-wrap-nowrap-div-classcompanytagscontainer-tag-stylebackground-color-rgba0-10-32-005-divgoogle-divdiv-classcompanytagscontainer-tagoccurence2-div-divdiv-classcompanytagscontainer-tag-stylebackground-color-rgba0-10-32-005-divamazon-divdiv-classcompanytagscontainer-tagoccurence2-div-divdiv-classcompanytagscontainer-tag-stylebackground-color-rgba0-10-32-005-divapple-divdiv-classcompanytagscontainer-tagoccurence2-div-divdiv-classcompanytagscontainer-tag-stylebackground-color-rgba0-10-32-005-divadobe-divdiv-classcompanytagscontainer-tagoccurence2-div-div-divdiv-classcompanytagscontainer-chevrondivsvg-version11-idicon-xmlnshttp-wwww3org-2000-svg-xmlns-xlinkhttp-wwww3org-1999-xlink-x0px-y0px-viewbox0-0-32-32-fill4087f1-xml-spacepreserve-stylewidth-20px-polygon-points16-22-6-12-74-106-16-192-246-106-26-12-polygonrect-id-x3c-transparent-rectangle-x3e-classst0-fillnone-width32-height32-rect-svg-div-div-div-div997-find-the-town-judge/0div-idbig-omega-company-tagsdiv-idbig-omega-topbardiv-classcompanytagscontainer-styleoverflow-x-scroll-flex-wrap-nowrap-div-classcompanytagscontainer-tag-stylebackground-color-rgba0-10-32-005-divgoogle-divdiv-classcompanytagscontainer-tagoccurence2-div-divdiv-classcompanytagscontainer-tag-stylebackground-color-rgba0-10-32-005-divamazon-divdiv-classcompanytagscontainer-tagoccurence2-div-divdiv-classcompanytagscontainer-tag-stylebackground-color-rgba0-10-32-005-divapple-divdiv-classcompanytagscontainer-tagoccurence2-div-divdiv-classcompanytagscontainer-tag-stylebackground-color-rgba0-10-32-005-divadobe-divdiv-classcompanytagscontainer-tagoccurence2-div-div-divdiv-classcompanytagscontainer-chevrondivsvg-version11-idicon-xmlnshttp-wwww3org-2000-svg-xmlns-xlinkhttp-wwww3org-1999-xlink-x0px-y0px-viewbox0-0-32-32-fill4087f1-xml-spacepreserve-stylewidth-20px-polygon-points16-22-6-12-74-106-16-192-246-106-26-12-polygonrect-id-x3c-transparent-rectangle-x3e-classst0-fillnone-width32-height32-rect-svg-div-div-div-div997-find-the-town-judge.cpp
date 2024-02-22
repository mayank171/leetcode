class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        map<int,set<int>> mp;
        
        for(int i=0;i<trust.size();i++)
        {
            int x=trust[i][0];
            mp[trust[i][1]].insert(x);
        }
        
        /*
        2 1
        3 2
        */
        
        //vector<int> cand;
        int cand=-1;
        for(int i=1;i<=n;i++)
        {
            if(mp[i].size()==n-1)
            {
                cand= i;
            }
        }
        
        for(auto &it:mp)
        {
            if(it.second.find(cand)!=it.second.end())
                return -1;
        }
        
        return cand;
    }
};