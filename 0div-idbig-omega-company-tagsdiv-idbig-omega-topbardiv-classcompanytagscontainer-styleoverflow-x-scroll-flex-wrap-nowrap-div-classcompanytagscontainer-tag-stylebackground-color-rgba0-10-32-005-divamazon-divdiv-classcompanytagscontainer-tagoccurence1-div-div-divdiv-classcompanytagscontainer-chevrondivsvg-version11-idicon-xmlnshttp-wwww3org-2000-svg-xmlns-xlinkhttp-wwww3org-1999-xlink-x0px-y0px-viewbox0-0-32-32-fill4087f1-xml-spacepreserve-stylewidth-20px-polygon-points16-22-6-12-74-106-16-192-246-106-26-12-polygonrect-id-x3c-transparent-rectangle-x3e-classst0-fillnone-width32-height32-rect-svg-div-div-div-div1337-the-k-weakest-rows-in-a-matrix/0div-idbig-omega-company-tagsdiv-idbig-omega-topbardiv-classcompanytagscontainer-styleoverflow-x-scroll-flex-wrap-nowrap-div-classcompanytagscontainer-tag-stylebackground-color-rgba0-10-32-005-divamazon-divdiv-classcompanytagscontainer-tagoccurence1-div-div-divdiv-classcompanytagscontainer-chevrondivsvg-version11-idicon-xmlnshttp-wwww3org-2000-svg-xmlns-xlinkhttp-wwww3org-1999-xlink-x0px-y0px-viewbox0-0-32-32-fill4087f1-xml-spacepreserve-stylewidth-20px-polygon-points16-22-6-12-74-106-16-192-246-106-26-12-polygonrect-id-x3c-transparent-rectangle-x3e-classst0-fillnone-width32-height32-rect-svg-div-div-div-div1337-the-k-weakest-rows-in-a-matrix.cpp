class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>> vp;
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    ct++;
                else
                    break;
            }
            vp.push_back({ct,i});
        }
        
        sort(vp.begin(),vp.end());
        
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            res.push_back(vp[i].second);
            k--;
            if(k==0)
                break;
        }
        
        return res;
    }
};