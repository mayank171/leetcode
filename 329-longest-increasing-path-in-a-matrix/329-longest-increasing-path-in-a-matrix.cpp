class Solution {
    
private:
    
//     void dfs(vector<vector<int>>& matrix, int x,int y,int row,int col,int &ct,int &max)
//     {
      
//         int dx[4]={-1,0,1,0};
//         int dy[4]={0,1,0,-1};
        
//         for(int i=0;i<4;i++)
//         {
//             int x_i=x+dx[i];
//             int y_i=y+dy[i];
       
//             if(x_i>=0 && x_i<row && y_i>=0 && y_i<col && matrix[x_i][y_i]>matrix[x][y])
//             {
//                 ct++;
                
//                 if(max<ct)
//                     max=ct;
                
//                 dfs(matrix,x_i,y_i,row,col,ct,max);
          
//                 ct--;
                
//             }
//         }
//     }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
       
//         int n=matrix.size();
//         int m=matrix[0].size();
        
//         int t=0;
      
//         for(int i=0;i<n;i++)
//         { 
//              for(int j=0;j<m;j++)
//              {
//                  int ct=0;
//                  dfs(matrix,i,j,n,m,ct,t);
//                  cout<<ct<<endl;
                 
//              }

//         }
        
//         return t+1;
        
        int rows = matrix.size();
        if (!rows) return 0;
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        std::function<int(int, int)> dfs = [&] (int x, int y) {
            if (dp[x][y]) return dp[x][y];
            vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (auto &dir : dirs) {
                int xx = x + dir[0], yy = y + dir[1];
                if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
                if (matrix[xx][yy] <= matrix[x][y]) continue;
                dp[x][y] = std::max(dp[x][y], dfs(xx, yy));
            }
            return ++dp[x][y];
        };
        
        int ret = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ret = std::max(ret, dfs(i, j));
            }
        }
        
        return ret;
    }
};