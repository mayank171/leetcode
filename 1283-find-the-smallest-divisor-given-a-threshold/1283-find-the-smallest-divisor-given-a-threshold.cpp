class Solution {
private:
    int blackBox(vector<int> &nums,int mid,int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%mid!=0)
            {
                sum+=nums[i]/mid+1;
            }
            else
            {
                sum+=nums[i]/mid;
            }
        }
       // cout<<sum<<endl;
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int thres) {
        
        int n=nums.size();
        
        int low=1;
        
        int high=*max_element(nums.begin(),nums.end());
        
        int ans=high;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(blackBox(nums,mid,n)<=thres)
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