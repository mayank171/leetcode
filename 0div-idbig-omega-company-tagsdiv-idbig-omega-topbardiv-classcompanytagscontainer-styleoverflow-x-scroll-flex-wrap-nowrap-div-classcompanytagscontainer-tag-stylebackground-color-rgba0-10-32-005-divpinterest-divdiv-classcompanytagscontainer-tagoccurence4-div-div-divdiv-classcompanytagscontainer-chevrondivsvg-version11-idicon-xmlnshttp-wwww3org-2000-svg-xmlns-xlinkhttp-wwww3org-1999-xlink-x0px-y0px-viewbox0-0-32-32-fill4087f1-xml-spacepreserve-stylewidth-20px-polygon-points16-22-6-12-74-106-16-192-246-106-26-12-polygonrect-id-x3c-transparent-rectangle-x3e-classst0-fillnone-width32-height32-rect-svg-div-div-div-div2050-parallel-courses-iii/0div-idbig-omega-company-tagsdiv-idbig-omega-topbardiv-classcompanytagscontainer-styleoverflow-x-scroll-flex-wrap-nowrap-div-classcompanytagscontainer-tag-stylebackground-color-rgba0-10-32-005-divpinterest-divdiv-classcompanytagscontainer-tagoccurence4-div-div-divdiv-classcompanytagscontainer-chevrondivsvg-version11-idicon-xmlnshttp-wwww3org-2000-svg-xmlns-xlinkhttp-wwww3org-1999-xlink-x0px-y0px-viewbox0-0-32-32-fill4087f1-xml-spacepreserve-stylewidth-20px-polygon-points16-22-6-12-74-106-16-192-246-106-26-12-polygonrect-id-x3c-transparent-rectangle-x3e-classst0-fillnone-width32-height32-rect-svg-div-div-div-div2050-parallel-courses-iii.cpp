class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> indeg(n+1,0);
        vector<int> adj[n+1];
        
        for(int i=0;i<relations.size();i++)
        {
            int u=relations[i][0];
            int v=relations[i][1];
            adj[u].push_back(v);
            
            indeg[v]++;
        }
        
        queue<int> q;
        vector<int> vis(n+1,0);
        set<int> st;
        vector<int> dist(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                st.insert(i);
                dist[i]=time[i-1];
                cout<<i<<endl;
            }
        }
        
        vector<int> res;
        
        int ans=0;
        while(!q.empty())
        {
            // int maxi=0;
            // for(auto &it:st)
            // {
            //     if(vis[it]==0)
            //     {
            //         vis[it]=1;
            //         maxi=max(maxi,time[it-1]);
            //     }
            // }
            // cout<<maxi<<"-"<<endl;
            // ans+=maxi;
            
            int node=q.front();
            res.push_back(node);
            q.pop();
            
            set<int> st1;
            for(auto &it:adj[node])
            {
                indeg[it]--;
                dist[it]=max(dist[it],dist[node]+time[it-1]);
                if(indeg[it]==0)
                {
                    q.push(it);
                    st.insert(it);
                }
            }
            
//             for(auto &it:st)
//             {
//                 if(st1.find(it)==st1.end())
//                 {
//                     dist[it]=min(dist[it],dist[node]+time[it-1]);    
//                 }
//             }
        }
        
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dist[i]);
        }
        cout<<endl;
        
        return ans;
    }
};













