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
                    if(grid[i][j]==0)
                        grid[i][j]=1;
                    else
                        grid[i][j]=0;
                }
            } 
        }
        
        for(int j=0;j<m;j++)
        {
            int ct_0=0;
            int ct_1=0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==0)
                    ct_0++;
                else
                    ct_1++;
            }
            
            if(ct_0>ct_1)
            {
                for(int i=0;i<n;i++)
                {
                    if(grid[i][j]==0)
                        grid[i][j]=1;
                    else
                        grid[i][j]=0;
                    
                }
            }
        }
        
        long long ans=0;
        
        
        
        for(int i=0;i<n;i++)
        {
            long long t=0;
            int p=m-1;
            for(int j=0;j<m;j++)
            {
                t+=grid[i][j]*pow(2,p);
                p--;
            }
            ans+=t;
        }
        
        
        return ans;
        
        
    }
};