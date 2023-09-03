class Solution {
public:
    int uniquePaths(int n, int m) {
        
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            ans[i][0]=1;
        }

        for(int i=0;i<m;i++)
        {
            ans[0][i]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                 ans[i][j]=ans[i-1][j]+ans[i][j-1];
            }
        }

        return ans[n-1][m-1];

    }
};