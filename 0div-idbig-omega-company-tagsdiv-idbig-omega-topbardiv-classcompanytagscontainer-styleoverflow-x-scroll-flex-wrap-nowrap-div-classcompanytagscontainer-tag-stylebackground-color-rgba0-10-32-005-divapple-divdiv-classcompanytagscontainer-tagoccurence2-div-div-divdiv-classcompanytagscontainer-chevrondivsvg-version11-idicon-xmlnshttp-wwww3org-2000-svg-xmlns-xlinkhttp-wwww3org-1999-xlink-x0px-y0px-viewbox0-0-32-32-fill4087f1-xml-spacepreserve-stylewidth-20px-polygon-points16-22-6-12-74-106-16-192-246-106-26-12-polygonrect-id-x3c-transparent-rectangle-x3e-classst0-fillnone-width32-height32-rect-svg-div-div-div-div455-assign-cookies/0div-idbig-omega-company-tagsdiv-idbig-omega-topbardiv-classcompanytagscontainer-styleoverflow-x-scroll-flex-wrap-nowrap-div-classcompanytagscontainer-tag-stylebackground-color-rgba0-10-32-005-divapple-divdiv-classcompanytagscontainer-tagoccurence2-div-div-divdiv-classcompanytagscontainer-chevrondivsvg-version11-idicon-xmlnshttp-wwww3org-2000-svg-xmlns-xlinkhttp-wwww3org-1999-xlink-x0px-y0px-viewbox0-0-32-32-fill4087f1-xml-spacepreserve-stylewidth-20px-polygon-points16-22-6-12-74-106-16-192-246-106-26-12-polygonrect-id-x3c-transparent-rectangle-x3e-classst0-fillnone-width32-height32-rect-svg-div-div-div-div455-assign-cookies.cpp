class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        multiset<int> st;
        
        for(int i=0;i<s.size();i++)
        {
            st.insert(s[i]);
        }
        
        int ct=0;
        for(int i=0;i<g.size();i++)
        {
            auto it=st.lower_bound(g[i]);
            if(it!=st.end())
            {
                ct++;
                st.erase(it);
            }
        }
        
        return ct;
        
    }
};