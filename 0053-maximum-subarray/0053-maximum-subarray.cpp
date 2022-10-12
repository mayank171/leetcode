class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size();
        
        int cursum=nums[0];
        int maxsum=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(cursum<0)
                cursum=nums[i];
            else
                cursum+=nums[i];
            
            maxsum=max(maxsum,cursum);
        }
        
        return maxsum;
        
    }
};