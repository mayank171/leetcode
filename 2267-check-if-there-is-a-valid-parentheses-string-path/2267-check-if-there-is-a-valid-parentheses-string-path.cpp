int dp[101][101][201];

class Solution {
public:
    
    bool dfs(vector<vector<char>>& grid,int x,int y,int n,int m,int open)
    {
       
       if(x==n-1 && y==m-1)
       {
           if(open==1 && grid[x][y]==')')
               return true;
           return false;
       }
        
       if(x>=n || y>=m)
           return false;
        
      
      
       if(grid[x][y]==')')
       {
           open--;
       }
       else
       {
           open++;
       }
        
        
       if(open<0)
           return false;
        
        if(dp[x][y][open]!=-1)
           return dp[x][y][open];
        
        
       bool ans=false;
        
       ans|=dfs(grid,x+1,y,n,m,open);
        
        
       ans|=dfs(grid,x,y+1,n,m,open);
    
        
       return dp[x][y][open]=ans;
    }
    
    
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[n-1][m-1]=='(')
            return false;
        
        if(grid[0][0]==')')
            return false;
    
        memset(dp, -1, sizeof(dp));
        
        int x=0;
        int y=0;
        
        int open=0;
        
        if(dfs(grid,x,y,n,m,open))
            return true;
        
        return false;
     
        
    }
};