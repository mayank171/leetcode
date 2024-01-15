class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        int n=matches.size();
        
        sort(matches.begin(),matches.end());
        
        map<int,vector<int>> mp2;
        
        for(int i=0;i<n;i++)
        {
            int w=matches[i][0];
            int l=matches[i][1];
            
            mp2[l].push_back(w);
        }
        
        vector<int> notlost;
        for(int i=0;i<n;i++)
        {
            
            int w=matches[i][0];
            
            if(i>0 && w==matches[i-1][0])
                continue;
            
            if(mp2.find(w)==mp2.end())
            {
                 notlost.push_back(w);        
            }
        }
        
        
        
        vector<int> lost1;
        for(auto &it:mp2)
        {
            if(it.second.size()==1)
                lost1.push_back(it.first);   
        }
        
        
        
        sort(notlost.begin(),notlost.end());
        sort(lost1.begin(),lost1.end());
        
        
        return {notlost,lost1};
    }
};