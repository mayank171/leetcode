class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<m;j++)
                {
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        
        
        for(int j=0;j<m;j++)
        {
            int ct1=0;
            int ct0=0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==1)
                    ct1++;
                else if(grid[i][j]==0)
                    ct0++;
            }
            
            if(ct0>ct1)
            {
                for(int i=0;i<n;i++)
                {
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int val=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    val+=(1<<(m-j-1));
                }
            }
            
       //     cout<<val<<endl;
            ans+=val;
        }
        
        return ans;
    }
};