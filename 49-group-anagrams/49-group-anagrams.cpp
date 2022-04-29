class Solution {
private:
    static bool comp(vector<string> a,vector<string> b)
    {
        if(a.size()<b.size())
            return true;
        return false;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        
        map<vector<int>,vector<string>> mp;
        
        int n=strs.size();
        
        for(int i=0;i<n;i++)
        {
            
            
            vector<int> freq(26,0);
            int len=strs[i].length();
            
            for(int j=0;j<len;j++)
            {
                freq[strs[i][j]-'a']++;    
            }
            
            mp[freq].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        
        
        for(auto &it:mp)
        {
            auto itr=it.second;
            vector<string> temp;
            for(auto &it1:itr)
            {
                cout<<it1<<" ";
                temp.push_back(it1);
            }
            ans.push_back(temp);
            cout<<endl;
        }
        
        sort(ans.begin(),ans.end(),comp);
        
        return ans;
            
        
        
    }
};