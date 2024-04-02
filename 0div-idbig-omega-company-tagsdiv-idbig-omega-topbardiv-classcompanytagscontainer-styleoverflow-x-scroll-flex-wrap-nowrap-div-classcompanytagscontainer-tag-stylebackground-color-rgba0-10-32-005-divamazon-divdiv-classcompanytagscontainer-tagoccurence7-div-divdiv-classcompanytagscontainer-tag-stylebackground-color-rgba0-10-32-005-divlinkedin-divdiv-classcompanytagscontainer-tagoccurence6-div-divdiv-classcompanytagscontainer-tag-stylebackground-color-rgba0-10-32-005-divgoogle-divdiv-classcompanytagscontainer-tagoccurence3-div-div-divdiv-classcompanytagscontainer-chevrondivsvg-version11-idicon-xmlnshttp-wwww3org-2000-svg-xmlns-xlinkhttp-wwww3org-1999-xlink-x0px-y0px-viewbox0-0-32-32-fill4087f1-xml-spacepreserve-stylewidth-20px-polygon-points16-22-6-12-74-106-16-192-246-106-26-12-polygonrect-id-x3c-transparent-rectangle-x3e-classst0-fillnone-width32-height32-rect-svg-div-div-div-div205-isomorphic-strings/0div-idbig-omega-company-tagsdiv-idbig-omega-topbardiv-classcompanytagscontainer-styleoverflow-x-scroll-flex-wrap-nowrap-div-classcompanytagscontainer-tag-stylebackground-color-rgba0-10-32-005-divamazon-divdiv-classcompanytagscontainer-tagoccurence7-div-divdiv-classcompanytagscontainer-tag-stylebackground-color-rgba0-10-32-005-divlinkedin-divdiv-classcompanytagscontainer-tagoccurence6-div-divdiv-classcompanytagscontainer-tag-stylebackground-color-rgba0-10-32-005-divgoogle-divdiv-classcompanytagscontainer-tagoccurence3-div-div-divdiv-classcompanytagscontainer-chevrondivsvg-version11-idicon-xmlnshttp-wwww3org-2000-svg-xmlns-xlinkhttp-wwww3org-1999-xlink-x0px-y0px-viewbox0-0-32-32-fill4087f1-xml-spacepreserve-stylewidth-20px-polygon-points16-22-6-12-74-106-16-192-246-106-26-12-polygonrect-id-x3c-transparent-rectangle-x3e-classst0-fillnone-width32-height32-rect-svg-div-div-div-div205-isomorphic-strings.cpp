class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char,char> mp;
        for(int i=0;i<s.length();i++)
        {
            int j=i;
            char ch=s[i];
            int ct=0;
            while(j<s.length() && s[j]==ch)
            {
                j++;
                ct++;
            }
            
            j=i;
            ch=t[i];
            set<char> st;
            int ct2=0;
            while(j<s.length() && t[j]==ch)
            {
                st.insert(t[j]);
                j++;
                ct2++;
            }
            
            if(st.size()!=1 || ct!=ct2)
                return false;
            
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=t[i];
            } 
            else if(mp[s[i]]!=t[i])
                return false;
            
            i=j-1;
        }
        
        map<char,char> mp1;
        for(int i=0;i<t.length();i++)
        {
            int j=i;
            char ch=t[i];
            int ct=0;
            while(j<t.length() && t[j]==ch)
            {
                j++;
                ct++;
            }
            
            j=i;
            ch=s[i];
            set<char> st;
            int ct2=0;
            while(j<t.length() && s[j]==ch)
            {
                st.insert(s[j]);
                j++;
                ct2++;
            }
            
            if(st.size()!=1 || ct!=ct2)
                return false;
            
            if(mp1.find(t[i])==mp1.end())
            {
                mp1[t[i]]=s[i];
            } 
            else if(mp1[t[i]]!=s[i])
                return false;
            
            i=j-1;
        }
        
        return true;
    }
};