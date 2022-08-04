class Solution {
private:
    int blackBox(vector<int> &nums,int n,int mid,int target)
    {
        int sum=0;
        
        for(int i=0;i<mid;i++)
        {
            sum+=nums[i];
        }
        
        if(sum>=target)
            return true;
        
        int ind=0;
        for(int i=mid;i<n;i++)
        {
            sum=sum-nums[ind]+nums[i];
            
            if(sum>=target)
                return true;
            
            ind++;
        }
        
        return false;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        
        int low=1;
        int high=n;
        
        int ans=0;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            int k=blackBox(nums,n,mid,target);
            
            if(k)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};