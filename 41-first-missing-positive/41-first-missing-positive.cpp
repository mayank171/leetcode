class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        
        bool one=false;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>n || nums[i]<1)
            {
                nums[i]=1;
            }
            else if(nums[i]==1)
            {
                one=true;
            }
        }
        
        if(one==false)
            return 1;
        
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0)
                continue;
            else
                nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                return i+1;
        }
        
        return n+1;
        
    }
};