class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
            return 0;
        
        int low=0;
        int high=n-1;
        
        while(low<high)
        {
            int  mid=(low+high)/2;
            
            
            if(nums[mid]>nums[mid+1])
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
                
        }
        
        return low;
        
//         int ans;
        
//         nums[low]>nums[high]?ans=low:ans=high;
        
//         return ans;
        
        
    }
};