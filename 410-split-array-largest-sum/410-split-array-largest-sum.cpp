class Solution {
private:
    int blackBox(vector<int> &nums,int max_sum,int m)
    {
        int n=nums.size();
        
        int sum=0;
        
        int ct=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>max_sum)
            {
                sum=0;
                ct++;
                if(ct>m)
                    return ct;
                i--;
                continue;
            }
        }
        
        if(sum>0)
            ct++;
        return ct;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        
        int n=nums.size();
        
        int low=*max_element(nums.begin(),nums.end());
        
        int high=0;
        
        for(int i=0;i<n;i++)
        {
            high+=nums[i];
        }
        
        int ans=high;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(blackBox(nums,mid,m)>m)
            {
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        
        return ans;
        
    }
};