class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        priority_queue<pair<int,pair<int,int>>> pq;
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int x=nums1[i];
                int y=nums2[j];
                
                if(pq.size()<k)
                {
                     pq.push({x+y,{x,y}});
                }
                else
                {
                    if(pq.top().first>x+y)
                    {
                        pq.pop();
                        pq.push({x+y,{x,y}});
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        
        return ans;
    }
};