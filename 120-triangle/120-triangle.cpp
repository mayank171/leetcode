class Solution {
private:
    int check(vector<vector<int>> &dp,vector<vector<int>> &triangle,int x,int y,int n)
    {
        if(x==n-1)
        {
            return dp[x][y]=triangle[x][y];
        }
        
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        
        int d=triangle[x][y]+check(dp,triangle,x+1,y,n);
        int r=triangle[x][y]+check(dp,triangle,x+1,y+1,n);
        
        return dp[x][y]=min(d,r);
        
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        check(dp,triangle,0,0,n);
       // cout<<"vmdvmkdv";
        
        return dp[0][0];
        
        
    }
};