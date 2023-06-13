class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(grid[i][j]);
            }
            
            for(int j=0;j<n;j++)
            {
                int flag=0;
                for(int k=0;k<n;k++)
                {
                    if(grid[k][j]!=temp[k])
                    {
                        flag=1;
                        break;
                    }
                }
                
                if(flag==0)
                    ans++;
            }
        }
        
        return ans;
    }
};