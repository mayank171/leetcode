class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int ct=1;
        int cur=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==cur)
            {
                ct++;
            }
            else
            {
                if(pq.size()<k)
                {
                    pq.push({ct,cur});
                }
                else if(pq.top().first<ct)
                {
                    pq.pop();
                    pq.push({ct,cur});
                }
                ct=1;
                cur=nums[i];
            }
        }
        
        if(pq.size()<k)
        {
            pq.push({ct,cur});
        }
        else if(pq.top().first<ct)
        {
            pq.pop();
            pq.push({ct,cur});
        }
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};