class Solution {
public:
    
    void solve(string &src,map<string,set<string>> &mp,multiset<pair<string,string>> &st,vector<string> &ans)
    {
        int flag=0;
        for(auto &it:mp[src])
        {
            string u=src;
            string v=it;
           
            auto it2=st.find({u,v});
            
            if(it2!=st.end())
            {
                st.erase(it2);
                solve(v,mp,st,ans);
            }
        }
        
        ans.push_back(src);
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        map<string,set<string>> mp;
        
        int size=tickets.size();
        
        multiset<pair<string,string>> st;
        
        for(int i=0;i<size;i++)
        {
            string u=tickets[i][0];
            string v=tickets[i][1];
            
            mp[u].insert(v);
            st.insert({u,v});
        }
        
        vector<string> ans;
        
        string src="JFK";
        solve(src,mp,st,ans);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};