class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int ans=0;
        int start=0;
        int end=0;
        int prod=1;
        
        while(start<n && end<n)
        {
            prod*=nums[end];
            
            while(start<n && prod>=k)
            {
                prod/=nums[start];
                start++;
            }
            
            if(prod<k)
            {
                ans+=end-start+1;
            }
            end++;
        }
        
        return ans;
        
        
    }
};