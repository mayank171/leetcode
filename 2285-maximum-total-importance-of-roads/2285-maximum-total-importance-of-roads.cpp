class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> indeg(n,0);
        
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            
            indeg[u]++;
            indeg[v]++;
        }
        
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({indeg[i],i});
        }
        
        sort(vp.begin(),vp.end());
        
        map<int,int> mp;
        int ind=1;
        for(int i=0;i<n;i++)
        {
            mp[vp[i].second]=ind;
            ind++;
        }
        
        long long ans=0;
        for(int i=0;i<roads.size();i++)
        {
            ans+=mp[roads[i][0]];
            ans+=mp[roads[i][1]];
        }
        
        return ans;
    }
};