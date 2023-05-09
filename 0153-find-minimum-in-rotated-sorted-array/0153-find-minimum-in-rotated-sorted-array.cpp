class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        
        int low=0;
        int high=n-1;
        int key=-100000;
        int ans=1e9;
        
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            //cout<<low<<" "<<mid<<" "<<high<<endl;
            
            
            ans=min(ans,nums[mid]);
            ans=min(ans,nums[low]);
            ans=min(ans,nums[high]);
            
                
            if(nums[mid]>=nums[low])
            {
                if(nums[mid]>key && nums[low]<=key)
                    high=mid-1;
                else 
                    low=mid+1;
            }
            else if(nums[mid]<nums[high])
            {
                if(nums[mid]<key && nums[high]>=key)
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        
    //    ans=min(ans,nums[mid]);
      //  ans=min(ans,nums[low]);
       // ans=min(ans,nums[high]);
            
        return ans;
        
    }
};