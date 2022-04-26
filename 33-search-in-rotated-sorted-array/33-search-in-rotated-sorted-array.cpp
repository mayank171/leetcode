class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        int low=0;
        int high=n-1;
        
        
        if(n==1 && nums[0]==target)
            return 0;
        else if(n==1 && nums[0]!=target)
            return -1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            
            if(nums[mid]==target)
                return mid;
            
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target && target<=nums[mid])
                {
                    if(nums[low]==target)
                        return low;
                    else
                        high=mid;
                }
                else 
                {
                    low=mid+1;
                }
            }
            else if(nums[mid]<nums[high])
            {
                if(nums[mid]<target && target<=nums[high])
                {
                    if(nums[high]==target)
                        return high;
                    else
                        low=mid+1;
                }
                else 
                {
                    high=mid;
                }
            }
            
        }
        
        return -1;
        
    }
};