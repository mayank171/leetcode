class Solution {
public:
    
    bool dfs(map<string,vector<pair<string,double>>> &mp, string u,string v,set<pair<string,string>> &vis,double &x)
    {
       // cout<<u<<" "<<x<<endl;
        if(u==v)
            return true;
        
        for(auto &it:mp[u])
        {
            string adjnode=it.first;
            double dist=it.second;
            
            if(vis.find({u,adjnode})!=vis.end())
            {
                vis.erase({u,adjnode});
                double temp=x;
                x*=dist;
                if(dfs(mp,adjnode,v,vis,x))
                    return true;
                vis.insert({u,adjnode});
                x/=dist;    
            }
        }
        
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        set<string> st;
        int size=equations.size();
        for(int i=0;i<size;i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            st.insert(u);
            st.insert(v);
        }
        
        map<string,vector<pair<string,double>>> mp;
        
        for(int i=0;i<size;i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u].push_back({v,values[i]});
            mp[v].push_back({u,1/values[i]});
        }
        
        // for(auto &it:mp)
        // {
        //     cout<<it.first<<"->";
        //     for(auto &it1:it.second)
        //     {
        //         cout<<it1.first<<","<<it1.second<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        int qsize=queries.size();
        vector<double> ans;
        
        for(int i=0;i<qsize;i++)
        {
            string u=queries[i][0];
            string v=queries[i][1];
            
            if(st.find(u)==st.end() || st.find(v)==st.end())
            {
                ans.push_back(-1);        
            }
            else if(u==v)
            {
                ans.push_back(1);
            }
            else
            {
                set<pair<string,string>> vis;
                for(int i=0;i<size;i++)
                {
                    string u=equations[i][0];
                    string v=equations[i][1];
                    vis.insert({u,v});
                    vis.insert({v,u});
                }
                
                double x=1;
                if(dfs(mp,u,v,vis,x))
                   ans.push_back(x);
                else
                   ans.push_back(-1);
            }
        }
        
        return ans;
    }
};