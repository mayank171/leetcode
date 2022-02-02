class Solution {
private:
    // static bool comp(vector<int> a,vector<int> b)
    // {
    //     if(abs(a[0]-a[1]+1)>=abs(b[0]-b[1]+1))
    //     {
    //         return true;
    //     }
    //     return false;
    // }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        
        sort(intervals.begin(),intervals.end());
        
         
        for(auto it:intervals)
        {
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        
        int left=-1,right=-1;
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            if(intervals[i][1]>right && intervals[i][0]>left)
            {
                left=intervals[i][0];
                c++;
            }
        
                right=max(right,intervals[i][1]);
            
        }
        
        
        return c;
        
    }
};