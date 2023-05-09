class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<m;j++)
            {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i<=j)
                   swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        
        
        
    }
};