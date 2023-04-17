class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int extra) {
        
        multiset<int> st;
        
        for(int i=0;i<v.size();i++)
        {
            st.insert(v[i]);
        }
        
        vector<bool> ans;
        for(int i=0;i<v.size();i++)
        {
            auto it=st.find(v[i]);
            
            if(it!=st.end())
            {
                int x=*it;
                st.erase(it);
                auto maxi=st.end();
                --maxi;
                if(x+extra>=*maxi)
                {
                    ans.push_back(true);
                }
                else
                {
                    ans.push_back(false);
                }
                st.insert(x);
            }
        }
        
        return ans;
        
    }
};