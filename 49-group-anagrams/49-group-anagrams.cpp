class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>> mp;
        
        int n=strs.size();
        
        for(int i=0;i<n;i++)
        {
            string s=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto &it:mp)
        {
            vector<string> temp;
            for(auto &it1:it.second)
            {
                temp.push_back(it1);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};