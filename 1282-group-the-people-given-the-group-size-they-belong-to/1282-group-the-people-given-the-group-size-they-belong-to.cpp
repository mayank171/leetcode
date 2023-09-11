class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        map<int,set<int>> mp;
        int n=groupSizes.size();
        
        for(int i=0;i<n;i++)
        {
            mp[groupSizes[i]].insert(i);
        }
        
        vector<vector<int>> ans;
        
        for(auto &it:mp)
        {
            int x=it.first;
            set<int> st=it.second;
            int sz=st.size();
            
            while(sz)
            {
                vector<int> v;
                for(auto &it1:st)
                {
                    v.push_back(it1);
                    if(v.size()==x)
                        break;
                }
                ans.push_back(v);
                
                for(auto &it2:v)
                {
                    mp[it.first].erase(it2);
                }
                sz-=v.size();
            }
        }
        
        return ans;
    }
};