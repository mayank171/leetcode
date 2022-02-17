class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> v1;
        
        for(int i=0;i<n;i++)
        {
            v1.push_back(*max_element(grid[i].begin(),grid[i].end()));
        }
        
        vector<int> v2;
        
        for(int j=0;j<m;j++)
        {
            int maxi=INT_MIN;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]>maxi)
                {
                    maxi=grid[i][j];
                }
            }
            v2.push_back(maxi);
        }
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum+=abs(grid[i][j]-min(v1[i],v2[j]));
                grid[i][j]=min(v1[i],v2[j]);
            }
        }
        
        return sum;
        
        
    }
};