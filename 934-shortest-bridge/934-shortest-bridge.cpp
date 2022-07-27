class Solution {
public:
    
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        int row=0;
        int col=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    row=i;
                    col=j;
                    break;
                }
            }
            if(row!=0 && col!=0)
                break;
        }
        
        vector<int> vis(n*m,0);
        vis[row*m+col]=1;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{row,col}});
        queue<pair<int,int>> q2;
        q2.push({row,col});
        
        while(!q2.empty())
        {
            int x=q2.front().first;
            int y=q2.front().second;
            q2.pop();
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+x;
                int ind_y=dy[ind]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && grid[ind_x][ind_y]==1 && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({0,{ind_x,ind_y}});
                    q2.push({ind_x,ind_y});
                }
            }
            
        }
        
        int ans=0;
        
        while(!q.empty())
        {
            int ct=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            if(grid[x][y]==1 && ct!=0)
            {
                ans=ct;
                break;
            }    
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            
            for(int ind=0;ind<4;ind++)
            {
                int ind_x=dx[ind]+x;
                int ind_y=dy[ind]+y;
                
                if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && vis[ind_x*m+ind_y]==0)
                {
                    vis[ind_x*m+ind_y]=1;
                    q.push({ct+1,{ind_x,ind_y}});
                }
            }
        }
        
        return ans-1;
        
    }
    
    
    
    
    
    
    
    
    
    
    
};