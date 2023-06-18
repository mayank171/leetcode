class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pq.push({grid[i][j],{i,j}});
            }
        }
        
        vector<vector<int>> dp(n,vector<int> (m,1));
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int mod=1e9+7;
        
        while(!pq.empty())
        {
            int val=pq.top().first;
            int ii=pq.top().second.first;
            int jj=pq.top().second.second;
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int ind_x=dx[i]+ii;
                int ind_y=dy[i]+jj;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && val<grid[ind_x][ind_y])
                {
                    dp[ind_x][ind_y]=(dp[ind_x][ind_y]+dp[ii][jj])%mod;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=(ans+dp[i][j])%mod;
            }
        }
        
        return ans;
    }
};