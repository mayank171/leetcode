class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        for(int i=0;i<n2;i++)
        {
            pq.push({nums1[0]+nums2[i],0,i});
        }
        
        for(int i=1;i<n1;i++)
        {
            pq.push({nums1[i]+nums2[0],i,0});
        }
        
        
        int smallest=0;
        vector<vector<int>> ans;
        
        while(smallest<k)
        {
            vector<int> v=pq.top();
            pq.pop();
            ans.push_back({nums1[v[1]],nums2[v[2]]});
            
            int i=v[1];
            int j=v[2];
            
            if(i+1<n1 && j+1<n2)
            {
                pq.push({nums1[i+1]+nums2[j+1],i+1,j+1});
            }
            smallest++;
        }
        
        return ans;
    }
};