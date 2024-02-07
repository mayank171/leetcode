class Solution {
public:
    string frequencySort(string s) {
        
        map<int,vector<char>> mp;
        map<char,int> mp2;
        
        for(int i=0;i<s.length();i++)
        {
            mp2[s[i]]++;
        }
        
        for(auto &it:mp2)
        {
            mp[it.second].push_back(it.first);
        }
        
        s.clear();
        
        for(auto &it:mp)
        {
            vector<char> v=it.second;
            for(auto &ch : v)
            {
                int x=it.first;
                while(x--)
                {
                    s+=ch;
                }
            }
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
};