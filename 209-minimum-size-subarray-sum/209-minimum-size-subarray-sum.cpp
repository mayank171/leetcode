class Solution {
private:
    
    int blackBox(vector<int> &nums,int n,int mid,int target)
    {
        int ind=0;
        
        int sum=0;
        while(ind<mid)
        {
            sum+=nums[ind];
            ind++;
        }
        
       // cout<<sum<<"--"<<endl;
         if(sum>=target)
                return mid;
        
        for(int i=1;i<=n-mid;i++)
        {
            sum-=nums[i-1];
            sum+=nums[i+mid-1];
           // cout<<sum<<endl;
            if(sum>=target)
                return mid;
        }
        
       // cout<<sum<<"**"<<endl;
        return INT_MAX;
        
    }
    
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        
        int low=1;
        int high=n;
        
        int ans=INT_MAX;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int val=blackBox(nums,n,mid,target);
            
            //cout<<val<<endl;
            
            if(val>=ans)
            {
                low=mid+1;
            }
            else
            {
                ans=val;
                high=mid;
            }
        }
        
        if(ans!=INT_MAX)
            return ans;
        
        return 0; 
        
    }
};