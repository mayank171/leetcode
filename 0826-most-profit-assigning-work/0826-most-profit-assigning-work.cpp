class Solution {
public:
    
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
//         2  4  6  8  10
//         10 20 30 40 50
        
//         4  5  6  7
            
//         20 20 30 30
            
        int n=difficulty.size();
        int m=worker.size();
        vector<pair<int,int>> vp;
    
        for(int i=0;i<n;i++)
        {
            vp.push_back({difficulty[i],profit[i]});
        }
        
        sort(vp.begin(),vp.end());
        sort(worker.begin(),worker.end());
        
        for(auto &it:vp)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        
        int ind=0;
        int ans=0;
        int maxi=0;
            
        for(int i=0;i<m;i++)
        {
            while(ind>=0 && ind<n && worker[i]>=vp[ind].first)
            {
                maxi=max(maxi,vp[ind].second);
                ind++;
            }
            cout<<maxi<<endl;
            ans+=maxi;
        }
        
        return ans;
    }
};