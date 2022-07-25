class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n=nums.size();
        
        int ct=0;
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                ct++;
            else
            {
                maxi=max(maxi,ct);
                ct=0;
            }
        }
        if(ct>=0)
            maxi=max(maxi,ct);
        
        return maxi;
        
    }
};