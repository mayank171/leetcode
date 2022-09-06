class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        vector<pair<int,int>> adj[n];
        
        int size=flights.size();
        
        for(int i=0;i<size;i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        
        vector<int> vis(n,INT_MAX);
        vis[src]=0;
        
        q.push({src,{0,0}});
        
        int ans=INT_MAX;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int cost=q.front().second.first;
            int curK=q.front().second.second;
            
            cout<<node<<" "<<cost<<" "<<curK<<endl;
            
            q.pop();
            
            if(node==dst)
            {
                ans=min(ans,cost);
            }
            
            if(curK>k)
            {
                continue;
            }
            
            for(auto &it:adj[node])
            {
                if(cost+it.second < vis[it.first])
                {
                    vis[it.first]=cost+it.second;
                    q.push({it.first,{vis[it.first],curK+1}});
                }
            }
            
        }
        
        
        if(ans==INT_MAX)
            return -1;
        return ans;
        
    }
};