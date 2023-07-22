class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    int solve(vector<vector<int>> &matrix,int n,int m,int i,int j,vector<vector<int>> &dp)
    {   
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int maxi=0;
        for(int ind=0;ind<4;ind++)
        {
            int ind_x=dx[ind]+i;
            int ind_y=dy[ind]+j;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && matrix[ind_x][ind_y]>matrix[i][j])
            {
                maxi=max(maxi,1+solve(matrix,n,m,ind_x,ind_y,dp));
            }
        }
        
        return dp[i][j]=maxi;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+10,vector<int>(m+10,-1));
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,solve(matrix,n,m,i,j,dp));
            }
        }
        
        return ans+1;
    }
};