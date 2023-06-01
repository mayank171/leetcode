class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        
        if(grid[0][0]!=0)
            return -1;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<int> vis(n*m,0);
        vis[0]=1;
        
        int ans=-1;
        while(!q.empty())
        {
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            if(x==n-1 && y==m-1)
            {
                ans=dist;
                break;
            }
            
            for(int ind=0;ind<8;ind++)
            {
                int ind_x=dx[ind]+x;
                int ind_y=dy[ind]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==0 && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({dist+1,{ind_x,ind_y}});
                }
            }
        }
        
        return ans;
        
    }
};