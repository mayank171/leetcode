class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        
        int first=-1;
        int e=-1;
        for(int i=0;i<n;i++)
        {
            if(e<intervals[i][0])
            {
                if(first!=-1)
                   ans.push_back({first,e});
                first=intervals[i][0];
                e=intervals[i][1];
            }
            else if(e<intervals[i][1])
            {
                e=intervals[i][1];
            }
            else
            {
                
            }
        }
        
        ans.push_back({first,e});
        
        return ans;
    }
};