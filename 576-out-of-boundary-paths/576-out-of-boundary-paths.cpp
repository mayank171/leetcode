class Solution {
private:
    int mod=1e9+7;
    int check(vector<vector<vector<int>>> &dp,int row,int col,int n,int m,int ind)
    {
        if(ind==0)
            return 0;
        
        if(dp[row][col][ind]!=-1)
            return dp[row][col][ind];
        
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int ct=0;
        for(int i=0;i<4;i++)
        {
            int ind_x=dx[i]+row;
            int ind_y=dy[i]+col;
            
            if(ind_x>=0 && ind_x<n && ind_y>=0 && ind_y<m)
            {
                ct=(ct+check(dp,ind_x,ind_y,n,m,ind-1))%mod;
            }
            else
            {
                ct++;
            }
        }
        
        return dp[row][col][ind]=ct;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        int ind=1;
        int ans=0;
        
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (maxMove+1,-1)));
    
        return check(dp,startRow,startColumn,m,n,maxMove);
       
        
    }
};