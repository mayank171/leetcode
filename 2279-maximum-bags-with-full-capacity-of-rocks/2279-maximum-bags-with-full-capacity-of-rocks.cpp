class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int aR) {
        
        vector<int> diff;
        
        int n=capacity.size();
        
        for(int i=0;i<n;i++)
        {
            diff.push_back(capacity[i]-rocks[i]);
        }
        
        sort(diff.begin(),diff.end());
        
        int ind=0;
        int ct=0;
        while(aR && ind<n)
        {
            if(diff[ind]<=aR)
            {
                aR-=diff[ind];
                ct++;
            }
            ind++;
        }
        
        return ct;
        
    }
};