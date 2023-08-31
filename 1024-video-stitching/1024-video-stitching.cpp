class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        int mini=0;
        int maxi=0;
        int ct=0;
        int n=clips.size();
        
        while(maxi<time)
        {
            int h=0;
            for(int i=0;i<n;i++)
            {
                if(clips[i][0]<=mini)
                {
                   maxi=max(maxi,clips[i][1]);
                }
            }
            if(mini==maxi)
                return -1;
            mini=maxi;
            ct++;
        }
        
        return ct;
    }
};