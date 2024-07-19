class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> row(n);
        vector<int> col(m);
        
        for(int i=0;i<n;i++)
        {
            int mini=1e9;
            for(int j=0;j<m;j++)
            {
                mini=min(mini,matrix[i][j]);
            }
            row[i]=mini;
        }
        
        for(int i=0;i<m;i++)
        {
            int maxi=0;
            for(int j=0;j<n;j++)
            {
                maxi=max(maxi,matrix[j][i]);
            }
            col[i]=maxi;
        }
        
      
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==row[i] && matrix[i][j]==col[j])
                    ans.push_back(matrix[i][j]);
            }
        }
        
        return ans;
    }
};