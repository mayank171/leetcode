class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int e=-1e9;
        int ct=0;
        
        for(int i=0;i<n;i++)
        {
            if(e<=intervals[i][0])
            {
                e=intervals[i][1];                
            }
            else if(e<intervals[i][1])
            {
                ct++;
            }
            else
            {
                e=intervals[i][1];
                ct++;
            }
        }
        
        return ct;
    }
};