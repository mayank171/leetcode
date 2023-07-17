class Solution {
public:
    
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
    int dfs(vector<vector<int>> &matrix,int n,int m,int i,int j,vector<vector<int>> &dp)
    {
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        //d++;
        
        int flag=0;
        int maxi=0;
        for(int ind=0;ind<4;ind++)
        {
            int ind_x=i+dx[ind];
            int ind_y=j+dy[ind];
                        
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m && matrix[i][j]<matrix[ind_x][ind_y])
            {
                flag=1;
                maxi=max(maxi,dfs(matrix,n,m,ind_x,ind_y,dp)+1);
            }
        }    
        
    //    vis[i*m+j]=0;
        
        return dp[i][j]=maxi;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(300,vector<int> (300,-1));
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ans=0;
                ans=dfs(matrix,n,m,i,j,dp);
                
                res=max(res,ans);
            }
            
        }
        
        return res+1;
    }
};