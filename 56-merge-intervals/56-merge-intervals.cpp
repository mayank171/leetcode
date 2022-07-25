class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>> vp;
        int n=intervals.size();
        
        for(int i=0;i<n;i++)
        {
           
            vp.push_back({intervals[i][0],intervals[i][1]});
        }
        
        sort(vp.begin(),vp.end());
        
        int start=vp[0].first;
        int end=vp[0].second;
        
        vector<vector<int>> ans;
        
        for(int i=1;i<n;i++)
        {
         
            if(vp[i].first>end)
            {
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                start=vp[i].first;
                end=vp[i].second;
            }
            else
            {
                end=max(end,vp[i].second);
            }
        }
        
        ans.push_back({start,end});
        
        return ans;
        
    }
};