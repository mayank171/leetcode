class Solution {
public:
    
    double dfs(map<string,vector<pair<string,double>>> &mp,string &s1,string &s2,set<string> &vis)
    {
        if(mp.find(s1)==mp.end() || mp.find(s2)==mp.end())
            return -1.0;
        
        if(s1==s2)
            return 1.0;
        
        vis.insert(s1);
        
        double val=1.0;
        for(auto &it:mp[s1])
        {
            if(vis.find(it.first)==vis.end())
            {
                double ans= dfs(mp,it.first,s2,vis);
                if(ans!=-1)
                    return ans*it.second;
            }
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& q) {
        
        int n1=eq.size();
        int n2=values.size();
        
        int qs=q.size();
        
        vector<pair<int,double>> adj[26];
        set<char> st;
        
        map<string,vector<pair<string,double>>> mp;
        
        for(int i=0;i<n1;i++)
        {
            string s1=eq[i][0];
            string s2=eq[i][1];
            
            mp[s1].push_back({s2,values[i]});
            mp[s2].push_back({s1,1/values[i]});
        }
        
        vector<double> ans;
        
        for(int i=0;i<qs;i++)
        {
            string s1=q[i][0];
            string s2=q[i][1];
            
            set<string> vis;
            double res=dfs(mp,s1,s2,vis);
            ans.push_back(res);
        }
        
        return ans;
        
    }
};
















