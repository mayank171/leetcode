class Solution {
public:
    int dp[101][101][202];
    bool isValid(int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n) return false;
        return true;
    }
    bool fun(int i,int j,vector<vector<char>>& grid,int k,int m,int n){
        if(i<0||j<0||i>=m||j>=n) return false;
        if(i==m-1 && j==n-1){
            if(grid[i][j]=='(') return false;
            else{
                if(k<=0) return false;
                else{
                    if(k==1) return true;
                    return false;
                }
            }
        }
        
        bool ans = false;
        if(grid[i][j]=='('){
            k++;
        }
        else if(grid[i][j]==')'){
            if(k<=0) return false;
            else k--;
        }
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        if(isValid(i,j+1,m,n)) ans|=fun(i,j+1,grid,k,m,n);
        if(isValid(i+1,j,m,n)) ans|=fun(i+1,j,grid,k,m,n);
        return dp[i][j][k] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,grid,0,m,n);
    }
};