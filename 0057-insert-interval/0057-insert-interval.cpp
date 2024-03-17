class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        int laststart=intervals[0][0];
        int lastend=intervals[0][1];
        vector<vector<int>> ans;
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>lastend)
            {
                ans.push_back({laststart,lastend});
                laststart=intervals[i][0];
                lastend=intervals[i][1];
            }
            else
            {
                lastend=max(lastend,intervals[i][1]);
            }
        }
        
        ans.push_back({laststart,lastend});
        
        return ans;
    }
};