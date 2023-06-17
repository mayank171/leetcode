class Solution {
public:
    
     bool static comp(vector<int> &a,vector<int> &b)
    {
        if(a[1]<b[1])
            return true;
        return false;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),comp);
        
        int ct=1;
        int end=pairs[0][1];
        
        for(int i=1;i<n;i++)
        {
            if(pairs[i][0]>end)
            {
                ct++;
                end=pairs[i][1];
            }
        }
        
        return ct;
    }
};