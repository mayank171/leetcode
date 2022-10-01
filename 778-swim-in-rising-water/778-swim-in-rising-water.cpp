class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> vis(n*m,1e8);
        vis[0]=grid[0][0];
        
        pq.push({grid[0][0],{0,0}});
        
        int ans=0;
        
        while(!pq.empty())
        {
            int minCost=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            
            if(x==n-1 && y==m-1)
            {
                ans=minCost;
                break;
            }
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+x;
                int ind_y=dy[ind]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]>max(minCost,grid[ind_x][ind_y]))
                {
                    vis[ind_x*m+ind_y]=max(minCost,grid[ind_x][ind_y]);
                    pq.push({max(minCost,grid[ind_x][ind_y]),{ind_x,ind_y}});
                }
            }
        }
        
        return ans;
        
    }
};