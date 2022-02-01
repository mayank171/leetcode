class Solution {
public:
    int numSplits(string s) {
        
        int l=s.length();
        
        vector<int> pref(l-1);
        vector<int> suf(l-1);
        
        unordered_set<char> st;
        
        for(int i=0;i<l-1;i++)
        {
            st.insert(s[i]);
            pref[i]=st.size();
        }
       
        
        if(st.size()==l)
        {
            return 1;
        }
        
        unordered_set<char> st1;
        
        reverse(s.begin(),s.end());
        
        for(int i=0;i<l-1;i++)
        {
            st1.insert(s[i]);
            suf[l-2-i]=st1.size();
        }
     
        int ct=0;
        
        for(int i=0;i<l-1;i++)
        {
            if(suf[i]==pref[i])
            {
                ct++;
            }
        }
        
        
        return ct;
        
        
        
    }
};
