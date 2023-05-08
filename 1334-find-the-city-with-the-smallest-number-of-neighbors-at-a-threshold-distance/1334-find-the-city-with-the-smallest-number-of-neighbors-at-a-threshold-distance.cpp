class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        
        vector<vector<int>> dp(n,vector<int> (n,1e9));
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            dp[u][v]=wt;
            dp[v][u]=wt;
        }
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dp[i][k]+dp[k][j]<dp[i][j])
                    {
                        dp[i][j]=dp[i][k]+dp[k][j];
                    }
                }
            }
        }
        
        int mini=1e9;
        int ind=-1;
        
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]<=dt)
                {
                    ct++;
                }
            }
            
            if(ct<=mini)
            {
                mini=ct;
                ind=i;
            }
        }
        
        return ind;
        
    }
};