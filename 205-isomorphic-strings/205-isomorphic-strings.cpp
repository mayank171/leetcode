class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        map<char,char> mp;
        set<char> st;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                
                if(mp[s[i]]!=t[i])
                    return false;
            }
            else if(st.find(t[i])!=st.end())
            {
                return false;
            }
            else
            {
                st.insert(t[i]);
                mp[s[i]]=t[i];
            }
        }
        
        return true;
        
    }
};