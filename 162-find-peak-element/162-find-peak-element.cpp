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
            
            if(abs(low-high)==1)
                break;
            
            if(mid+1<n && nums[mid]>nums[mid+1])
            {
                high=mid;
            }
            else if(mid+1<n && nums[mid]<nums[mid+1])
            {
                low=mid+1;
            }
                
        }
        
        
        
        int ans;
        
        nums[low]>nums[high]?ans=low:ans=high;
        
        return ans;
        
        
    }
};