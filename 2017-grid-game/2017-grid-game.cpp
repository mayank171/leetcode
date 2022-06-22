class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        long long n=2;
        long long m=grid[0].size();
        
        vector<vector<long long>> grid1;
        
        for(int i=0;i<n;i++)
        {
            vector<long long> temp;
           for(int j=0;j<m;j++)
           {
               temp.push_back(grid[i][j]);
           }
           grid1.push_back(temp);
        }
        
        
        
        for(long long i=1;i<m;i++)
        {
            grid1[1][i]+=grid1[1][i-1];
        }
        
        for(long long i=1;i<m;i++)
        {
            grid1[0][i]+=grid1[0][i-1];
        }
        
        long long mini=LONG_MAX;
        
        for(long long i=0;i<m;i++)
        {
            if(i==0)
               mini=grid1[0][m-1]-grid1[0][i];
           
            else
            {
                long long maxi;
                if(grid1[0][m-1]-grid1[0][i]>grid1[1][i-1])
                    maxi=grid1[0][m-1]-grid1[0][i];
                else
                    maxi=grid1[1][i-1];
                
                if(mini>maxi)
                    mini=maxi;
                    
               // mini=min(mini,max(grid[0][m-1]-grid[0][i],grid[1][i-1]));
            }
                
        }
        
        return mini;
           
    }
};