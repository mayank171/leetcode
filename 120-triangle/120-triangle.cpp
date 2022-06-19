class Solution {
private:
//     int check(vector<vector<int>> &dp,vector<vector<int>> &triangle,int x,int y,int n)
//     {
//         if(x==n-1)
//         {
//             return dp[x][y]=triangle[x][y];
//         }
        
//         if(dp[x][y]!=-1)
//         {
//             return dp[x][y];
//         }
        
//         int d=triangle[x][y]+check(dp,triangle,x+1,y,n);
//         int r=triangle[x][y]+check(dp,triangle,x+1,y+1,n);
        
//         return dp[x][y]=min(d,r);
        
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
//         int n=triangle.size();
        
//         vector<vector<int>> dp(n,vector<int>(n,-1));
        
//         check(dp,triangle,0,0,n);
//        // cout<<"vmdvmkdv";
        
//         return dp[0][0];
        
        int n=triangle.size();
        
        vector<int> front(n,0);
        vector<int> cur(n,INT_MAX);
        
        for(int i=0;i<n;i++)
        {
            front[i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int diag=triangle[i][j]+front[j+1];
                int d=triangle[i][j]+front[j];
                cur[j]=min(diag,d);
                
            }
            front=cur;
        }
        
        
        // for(auto &it:front)
        // {
        //     cout<<it<<" ";
        // }
        
        
        return front[0];
        
        
        
        
        
        
        
        
        
        
        
        
    }
};