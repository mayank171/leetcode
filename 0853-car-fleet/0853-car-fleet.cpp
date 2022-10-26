class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n=position.size();
        
        vector<pair<int,int>> dis;
        
        for(int i=0;i<n;i++)
        {
            dis.push_back({position[i],speed[i]});
        }
        
        sort(dis.begin(),dis.end());
        
        vector<double> vp;
        
        for(int i=0;i<n;i++)
        {
            double x=(target-dis[i].first)/(double)dis[i].second;
            vp.push_back(x);
        }
        
        for(auto &it:vp)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        int ct=1;
        double maxi=vp.back();
        
        
        for(int i=n-1;i>=0;i--)
        {
            if(vp[i]>maxi)
            {
                ct++;
                maxi=vp[i];
            }
            
        }
        
        
        
        return ct;
        
    }
};