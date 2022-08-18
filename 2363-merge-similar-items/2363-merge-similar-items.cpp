class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        int n=items1.size();
        int m=items2.size();
        
        map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[items1[i][0]].push_back(items1[i][1]);
        }
        
        for(int i=0;i<m;i++)
        {
            mp[items2[i][0]].push_back(items2[i][1]);
        }
        
        
        vector<vector<int>> ans;
        
        for(auto &it:mp)
        {
            int sum=accumulate(it.second.begin(),it.second.end(),0);
            ans.push_back({it.first,sum});
        }
        
        sort(ans.begin(),ans.end());
        
        
        return ans;
        
        
    }
};