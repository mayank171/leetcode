class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        vector<pair<double,int>> vp;
        
        int n=quality.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({1.0*wage[i]/quality[i],quality[i]});
        }
        
        sort(vp.begin(),vp.end());
        
        double ans=1e15;
        int qsum=0;
        priority_queue<int> pq;
        for(auto &it:vp)
        {
            double ratio=it.first;
            qsum+=it.second;
            pq.push(it.second);
            
            if(pq.size()>k)
            {
                qsum-=pq.top();
                pq.pop();
            }
            
            if(pq.size()==k)
            {
                ans=min(ans,qsum*ratio);
            }
        }
        
        return ans;
    }
};