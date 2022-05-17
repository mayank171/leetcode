class Solution {
private:
    int check(int x,int y,int n,int m,vector<vector<int>> &dp, vector< vector< int> > &mat)
    {
    	if(x==0 && y==0)
    	{
    		return dp[0][0]=1;
    	}
    	
    	if(x<0 || y<0)
    		return 0;
    	
    	if(mat[x][y]==1)
    	{
    		return 0;
    	}
    	
    	if(dp[x][y]!=-1)
    	{
    		return dp[x][y];
    	}
    	
    	int left=check(x-1,y,n,m,dp,mat);
    	int right=check(x,y-1,n,m,dp,mat);
    	
    	long long xi=0;
    	xi+=left;
    	xi+=right;
    	return dp[x][y]=xi;
    	
    }

    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
        
        int n=mat.size();
        int m=mat[0].size();
        
        if(mat[0][0]==1 || mat[n-1][m-1]==1)
            return 0;
        
        
        vector<vector<int>> dp(n,vector<int> (m,-1));
	    int x=n-1;
	    int y=m-1;
	    
	    check(x,y,n,m,dp,mat);
	    
	    for(int i=0;i<n;i++)
	    {
	    	for(int j=0;j<m;j++)
	    	{
	    		cout<<dp[i][j]<<" ";
	    }
	    	cout<<endl;
	    }
	    
        if(dp[n-1][m-1]!=-1)
	    return dp[n-1][m-1];
        
        return 0;
	
    }
};