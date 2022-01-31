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
        

        int ct=1;
        
        int left=intervals[0][0];
        int right=intervals[0][1];
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>left && intervals[i][1]>right)
            {
                ct++;
                left=intervals[i][0];
                //right=intervals[i][1];
            }
            right=max(right,intervals[i][1]);
        }
        
        return ct;
        
//         for(auto it:intervals)
//         {
//             cout<<it[0]<<" "<<it[1]<<endl;
//         }
        
//         return 0;
        
    }
};