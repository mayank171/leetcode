class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        if(target<mat[0][0])
            return false;
        
        int low=0;
        int high=n*m-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            int row=mid/m;

            if(mat[row][0]==target)
            {
                return true;
            }
            else if(mat[row][0]>target)
            {
                row--;
                int ind=lower_bound(mat[row].begin(),mat[row].end(),target)-mat[row].begin();
                if(ind==m)
                    return false;
                else if(mat[row][ind]>target)
                    high=mid-1;
                else
                    return true;
            } else {
                // row--;
                int ind = lower_bound(mat[row].begin(), mat[row].end(), target) -
                          mat[row].begin();
                if (ind == m)
                    low = mid + 1;
                else if (mat[row][ind] > target)
                    return false;
                else
                    return true;
            }
        }

        return false;
    }
};