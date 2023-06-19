class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        reverse(gain.begin(),gain.end());
        gain.push_back(0);
        reverse(gain.begin(),gain.end());
        
        for(int i=1;i<gain.size();i++)
        {
            gain[i]=gain[i]+gain[i-1];
        }
        
        return *max_element(gain.begin(),gain.end());
        
    }
};