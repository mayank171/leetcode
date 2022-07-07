class Solution {
private:
    int helper(vector<vector<int>> &dp,vector<vector<int>> &matrix,int n,int m,int x,int y)
    {
        if(y<0 || y>=m)
            return 1e8;
        
        if(x==n-1)
        {
            return matrix[x][y];
        }
        
        if(dp[x][y]!=-1)
            return dp[x][y];
        
       // cout<<x<<" "<<y<<endl;
        int ldiag=matrix[x][y]+helper(dp,matrix,n,m,x+1,y-1);
        int below=matrix[x][y]+helper(dp,matrix,n,m,x+1,y);
        int rdiag=matrix[x][y]+helper(dp,matrix,n,m,x+1,y+1);
        
        return dp[x][y]=min(ldiag,min(below,rdiag));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        
        int ans=1e8;
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i=0;i<m;i++)
        {
            ans=min(ans,helper(dp,matrix,n,m,0,i));
            
        }
        
        return ans;
        
    }
};