class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n=points.size();
        sort(points.begin(),points.end());
        
        for(auto &it:points)
        {
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        cout<<endl;
        
        int start=points[0][0];
        int end=points[0][1];
        
        int ct=0;
        
        for(int i=1;i<n;i++)
        {
            if(points[i][0]<=end)
            {
                start=points[i][0];
                end=min(end,points[i][1]);
            }
            else
            {
                ct++;
                start=points[i][0];
                end=points[i][1];
            }
        }
        
        ct++;
//         ---
//           ---
            
//         ----
//          --
        
        return ct;
    }
};