class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> ans;
        
        for(int i=0;i<=n-3;i++)
        {
            vector<int> temp;
            for(int j=0;j<=m-3;j++)
            {
                int maxi=-1e9;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        maxi=max(maxi,grid[k][l]);
                    }
                }
            //    cout<<maxi<<endl;
                temp.push_back(maxi);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};