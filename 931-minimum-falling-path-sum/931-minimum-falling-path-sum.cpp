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
        
        vector<vector<int>> dp(n,vector<int>(m,1e8));
        
//         for(int i=0;i<m;i++)
//         {
//             ans=min(ans,helper(dp,matrix,n,m,0,i));
            
//         }
        
//         return ans;
        
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ldiag=1e8;int rdiag=1e8;int above=1e8;
                if(j-1>=0)
                    ldiag=matrix[i][j]+dp[i-1][j-1];
                above=matrix[i][j]+dp[i-1][j];
                if(j+1<m)
                    rdiag=matrix[i][j]+dp[i-1][j+1];
                
                dp[i][j]=min(ldiag,min(rdiag,above));
            }
        }
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        ans=*min_element(dp[n-1].begin(),dp[n-1].end());
        
            
        return ans;
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
    }
};