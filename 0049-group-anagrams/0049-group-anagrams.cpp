class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n=strs.size();
        
        map<string,vector<string>> mp;
        
        for(int i=0;i<n;i++)
        {
            string s=strs[i];
            string pat="";
            for(int j=0;j<s.size();j++)
            {
                pat+=s[j];
            }
            
            sort(pat.begin(),pat.end());
            
            mp[pat].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto &it:mp)
        {
            // cout<<it.first<<"->";
            // for(auto &it1:it.second)
            // {
            //     cout<<it1<<" ";
            // }
            // cout<<endl;
            ans.push_back(it.second);
        }
        
        return ans;
    }
};