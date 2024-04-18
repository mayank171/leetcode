class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int ct=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    for(int ind=0;ind<4;ind++)
                    {
                        int ind_x=dx[ind]+i;
                        int ind_y=dy[ind]+j;

                        if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==0)
                        {
                            ct++;   
                        }
                        else if(ind_x<0 || ind_x==n || ind_y<0 || ind_y==m)
                        {
                            ct++;
                        }
                    }
                }
            }
        }
        
        
        return ct;
    }
};