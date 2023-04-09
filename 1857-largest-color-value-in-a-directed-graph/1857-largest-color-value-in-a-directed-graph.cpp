class Solution {
public:
    
    
   
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        map<int,char> mp;
        
        int n=colors.size();
        for(int i=0;i<n;i++)
        {
            mp[i]=colors[i];
        }
        
        int size=edges.size();
        vector<int> adj[n];
        
        for(int i=0;i<size;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> indeg(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indeg[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        vector<vector<int>> dp(n,vector<int> (26,0));
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                dp[i][colors[i]-'a']=1;
            }
        }
        
        int ct=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            ct++;
            
            for(auto &it:adj[node])
            {
                for(int i=0;i<26;i++)
                {
                    dp[it][i]=max(dp[it][i],dp[node][i]+(i==colors[it]-'a'));
                }
                
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        
        if(ct<n)
            return -1;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
                       
    }
};










