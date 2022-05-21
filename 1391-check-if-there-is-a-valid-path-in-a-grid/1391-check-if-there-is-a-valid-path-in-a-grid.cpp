class Solution {
private:
    
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> vis(n*m,0);
        
        queue<pair<int,int>> q;
        
        q.push({0,0});
        vis[0]=1;
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
           // cout<<x<<" "<<y<<endl;
            q.pop();
            
            if(x==n-1 && y==m-1)
                return true;
            
            if(grid[x][y]==1)
            {
                int i=x;
                int j=y-1;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==4 || grid[i][j]==6 || grid[i][j]==1 ))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
                i=x;
                j=y+1;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==3 || grid[i][j]==5 || grid[i][j]==1))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
            }
            else if(grid[x][y]==2)
            {
                int i=x-1;
                int j=y;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==4 || grid[i][j]==3 || grid[i][j]==2))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
                i=x+1;
                j=y;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==5 || grid[i][j]==6 || grid[i][j]==2))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
            }
            else if(grid[x][y]==3)
            {
                int i=x;
                int j=y-1;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==1 || grid[i][j]==4 || grid[i][j]==6))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
                i=x+1;
                j=y;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==5 || grid[i][j]==6 || grid[i][j]==2))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
            }
            else if(grid[x][y]==4)
            {
                int i=x;
                int j=y+1;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==3 || grid[i][j]==1 || grid[i][j]==5))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
                i=x+1;
                j=y;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==2 || grid[i][j]==5 || grid[i][j]==6))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
            }
            else if(grid[x][y]==5)
            {
                int i=x-1;
                int j=y;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==3 || grid[i][j]==4 || grid[i][j]==2))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
                i=x;
                j=y-1;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==4 || grid[i][j]==6 || grid[i][j]==1))
                {
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
            }
            else if(grid[x][y]==6)
            {
                int i=x-1;
                int j=y;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==2 || grid[i][j]==3 || grid[i][j]==4))
                {
                    cout<<i<<j<<endl;
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
                i=x;
                j=y+1;
                
                if(i>=0 && i<n && j>=0 && j<m && vis[i*m+j]==0 && (grid[i][j]==1 || grid[i][j]==3 || grid[i][j]==5))
                {
                    cout<<i<<j<<endl;
                    q.push({i,j});
                    vis[i*m+j]=1;
                }
                
            }
            
            
            
        }
        
        return false;
        
    }
};