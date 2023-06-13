class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=1e9;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
          //  cout<<low<<" "<<high<<" "<<ans<<endl;
            
            if(nums[mid]<=nums[low] && nums[mid]<=nums[high])
            {
                ans=min(ans,nums[mid]);
                if(nums[low]<nums[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            else if(nums[mid]>nums[low] && nums[mid]>nums[high])
            {
                if(nums[low]<nums[high])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(nums[low]<nums[high])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
        }
        
        return ans;
    }
};