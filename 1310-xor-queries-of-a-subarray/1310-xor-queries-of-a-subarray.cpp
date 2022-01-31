class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        
        vector<int> ans;
        
        int n=arr.size();
        
        vector<int> prefix(n);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                prefix[i]=arr[i];
            }
            else
            {
                prefix[i]=prefix[i-1]^arr[i];
            }
                
        }
        
        int qs=q.size();
        
        for(int i=0;i<qs;i++)
        {
            int start=q[i][0];
            int end=q[i][1];
            if(start==0)
            {
                ans.push_back(prefix[end]);
            }
            else
            {
                ans.push_back(prefix[start-1]^prefix[end]);
            }
        }
        
        
        return ans;
        
    }
};