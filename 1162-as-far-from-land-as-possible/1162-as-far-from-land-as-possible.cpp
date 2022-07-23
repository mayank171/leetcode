class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    grid[i][j]=-1;
                }
                else
                {
                    grid[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        
        while(!q.empty())
        {
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=x+dx[ind];
                int ind_y=y+dy[ind];
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==-1)
                {
                    grid[ind_x][ind_y]=dist+1;
                    q.push({dist+1,{ind_x,ind_y}});
                }
            }
        }
        
        int maxi=-1e8;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>maxi)
                    maxi=grid[i][j];
            }
        }
        
        if(maxi==0)
            return -1;
        
        return maxi;
        
    }
};