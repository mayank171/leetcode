class Solution {
public:
    int check(vector<vector<vector<int>>> &dp, vector<vector<int>> &grid,int n,int m,int i,int j1,int j2)
    {
        if(j1<0 || j1>=m || j2<0 || j2>=m)
            return 0;
        
        if(i==n-1)
        {
            if(j1==j2)
                return dp[i][j1][j2]= grid[i][j1];
            return dp[i][j1][j2]= grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        
        
        int maxi=-1e8;
        for(int x=-1;x<=1;x++)
        {
            for(int y=-1;y<=1;y++)
            {
                if(j1==j2)
                {
                    maxi=max(maxi,grid[i][j1]+check(dp,grid,n,m,i+1,x+j1,y+j2));
                }
                else
                {
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+check(dp,grid,n,m,i+1,x+j1,y+j2));
                }
            }
        }
        
        return dp[i][j1][j2]=maxi;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
        
        return check(dp,grid,n,m,0,0,m-1);
        
    }
};