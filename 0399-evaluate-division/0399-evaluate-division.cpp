class Solution {
public:
    
    bool solve(string src,string dest,map<string,vector<pair<string,double>>> &mp,set<string> &st1,double &res)
    {
        if(src==dest)
            return true; 
        
        st1.insert(src);
        
        for(auto &it:mp[src])
        {
            string adjnode=it.first;
            double wt=it.second;
            
            if(st1.find(adjnode)==st1.end())
            {
                res*=wt;
                if(solve(adjnode,dest,mp,st1,res))
                    return true;
                res/=wt;    
            }
        }
        
        st1.erase(src);
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n=equations.size();
        map<string,vector<pair<string,double>>> mp;
        set<string> st;
        
        for(int i=0;i<n;i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            
            mp[u].push_back({v,values[i]});
            mp[v].push_back({u,1/(double)values[i]});
            st.insert(u);
            st.insert(v);
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
        
        int size=queries.size();
        vector<double> ans;
        for(int i=0;i<size;i++)
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
                set<string> st1;
                double res=1;
                if(solve(u,v,mp,st1,res))
                    ans.push_back(res);
                else
                    ans.push_back(-1);
            }
        }
        
        return ans;
    }
};