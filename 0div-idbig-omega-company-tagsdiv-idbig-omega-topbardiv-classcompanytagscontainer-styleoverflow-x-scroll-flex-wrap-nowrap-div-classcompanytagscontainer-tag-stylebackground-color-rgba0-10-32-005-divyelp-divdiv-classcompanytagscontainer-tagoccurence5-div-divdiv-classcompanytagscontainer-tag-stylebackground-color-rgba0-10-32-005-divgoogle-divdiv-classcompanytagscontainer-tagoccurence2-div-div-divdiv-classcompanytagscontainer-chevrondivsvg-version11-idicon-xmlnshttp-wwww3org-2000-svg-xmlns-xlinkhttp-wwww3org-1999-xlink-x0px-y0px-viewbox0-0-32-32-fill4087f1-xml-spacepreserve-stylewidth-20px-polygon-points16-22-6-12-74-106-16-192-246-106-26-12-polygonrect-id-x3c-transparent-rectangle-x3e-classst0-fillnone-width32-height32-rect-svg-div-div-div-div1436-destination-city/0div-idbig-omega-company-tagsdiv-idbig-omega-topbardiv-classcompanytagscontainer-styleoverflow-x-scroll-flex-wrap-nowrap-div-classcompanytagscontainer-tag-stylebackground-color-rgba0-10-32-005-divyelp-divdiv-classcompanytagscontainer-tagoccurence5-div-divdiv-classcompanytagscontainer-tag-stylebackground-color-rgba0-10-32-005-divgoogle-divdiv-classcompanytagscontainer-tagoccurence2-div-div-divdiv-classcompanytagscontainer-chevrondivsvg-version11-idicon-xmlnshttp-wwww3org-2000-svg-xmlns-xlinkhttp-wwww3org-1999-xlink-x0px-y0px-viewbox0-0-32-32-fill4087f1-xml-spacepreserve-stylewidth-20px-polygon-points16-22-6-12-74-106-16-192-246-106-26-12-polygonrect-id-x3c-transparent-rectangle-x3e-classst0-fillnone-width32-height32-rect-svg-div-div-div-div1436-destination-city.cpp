class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        map<string,string> mp;
        
        int n=paths.size();
        
        for(int i=0;i<n;i++)
        {
            string src=paths[i][0];
            string dest=paths[i][1];
            
            mp[src]=dest;
        }
        
        for(auto &it:mp)
        {
            string d=it.second;
            if(mp.find(it.second)==mp.end())
                return d;
        }
        
        
        return "";
          
    }
};