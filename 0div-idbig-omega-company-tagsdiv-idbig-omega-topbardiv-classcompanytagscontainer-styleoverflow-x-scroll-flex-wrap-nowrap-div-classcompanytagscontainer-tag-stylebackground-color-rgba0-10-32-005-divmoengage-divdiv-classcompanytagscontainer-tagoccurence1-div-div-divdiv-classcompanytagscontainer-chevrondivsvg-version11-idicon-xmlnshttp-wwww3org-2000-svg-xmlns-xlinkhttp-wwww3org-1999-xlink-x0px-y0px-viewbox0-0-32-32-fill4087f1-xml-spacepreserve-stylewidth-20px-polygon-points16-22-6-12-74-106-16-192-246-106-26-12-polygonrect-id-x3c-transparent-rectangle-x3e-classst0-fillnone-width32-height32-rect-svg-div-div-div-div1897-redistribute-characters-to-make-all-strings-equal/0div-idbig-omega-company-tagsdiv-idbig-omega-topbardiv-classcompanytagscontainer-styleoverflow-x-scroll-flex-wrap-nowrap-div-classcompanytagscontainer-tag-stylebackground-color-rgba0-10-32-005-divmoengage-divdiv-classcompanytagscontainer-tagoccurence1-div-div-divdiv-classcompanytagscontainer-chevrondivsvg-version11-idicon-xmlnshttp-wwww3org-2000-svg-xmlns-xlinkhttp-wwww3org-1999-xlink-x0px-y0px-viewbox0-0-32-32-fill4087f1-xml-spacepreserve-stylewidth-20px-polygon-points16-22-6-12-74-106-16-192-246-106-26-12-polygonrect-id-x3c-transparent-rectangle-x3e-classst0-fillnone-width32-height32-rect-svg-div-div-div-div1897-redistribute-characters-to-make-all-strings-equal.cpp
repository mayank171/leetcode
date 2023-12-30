class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        if(words.size()==1)
            return true;
        
        map<char,int> mp;
        
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            
            for(int j=0;j<s.length();j++)
            {
                mp[s[j]]++;
            }
        }
        
        int ct=words.size();
        
        for(auto &it:mp)
        {
            if(it.second%ct!=0)
                return false;
        }
        
        return true;
    }
};