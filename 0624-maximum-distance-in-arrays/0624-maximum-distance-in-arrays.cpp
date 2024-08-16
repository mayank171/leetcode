class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int n=arrays.size();
        
        int mini=arrays[0][0];
        int maxi=arrays[0][arrays[0].size()-1];
        int ans=0;
        
        for(int i=1;i<n;i++)
        {
            int curmin=arrays[i][0];
            int curmax=arrays[i][arrays[i].size()-1];
                
            int res1=abs(curmin-maxi);
            int res2=abs(curmax-mini);
            
            ans=max(ans,max(res1,res2));
            
            mini=min(mini,curmin);
            maxi=max(maxi,curmax);
        }
        
        return ans;
    }
};




















