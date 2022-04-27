class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        
        int low=0;
        int high=n-1;
        
        while(low<high)
        {
            if(low==high)
            {
                break;
            }
            
            int mid=(low+high)/2;
         
            if(nums[mid]<nums[high])
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        
        cout<<low<<" "<<high<<endl;
        
        return min(nums[low],nums[high]);
        
        
    }
};