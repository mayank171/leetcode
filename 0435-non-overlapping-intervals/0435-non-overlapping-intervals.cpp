class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int ct=0;
        int x=intervals[0][1];
        
        for(int i=1;i<n;i++)
        {
            if(x<=intervals[i][0])
            {
                x=intervals[i][1];
            }
            else if(x<=intervals[i][1])
            {
                ct++;
            }
            else if(x>intervals[i][1])
            {
                ct++;
                x=intervals[i][1];
            }
        }
        
        return ct;
        
    }
};