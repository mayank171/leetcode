class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,int>> vp;
        int n=position.size();
        
        for(int i=0;i<n;i++)
        {
            vp.push_back({position[i],speed[i]});
        }
        
        sort(vp.begin(),vp.end());
        
        int ct=1;
        double curtime=(target-vp.back().first)/(double)vp.back().second;
        
        for(int i=n-2;i>=0;i--)
        {
            double time=(target-vp[i].first)/(double)vp[i].second;
            if(time>curtime)
            {
                ct++;
                curtime=time;
            }
        }
        
        return ct;
        
    }
};