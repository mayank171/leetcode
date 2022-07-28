class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int row=-1;
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]<=target)
                row=i;
        }
        
        if(row==-1)
            return false;
        
        int ind=lower_bound(mat[row].begin(),mat[row].end(),target)-mat[row].begin();
        
        if(ind==m)
            return false;
        if(mat[row][ind]==target)
            return true;
        else
            return false;
    
        
    }
};