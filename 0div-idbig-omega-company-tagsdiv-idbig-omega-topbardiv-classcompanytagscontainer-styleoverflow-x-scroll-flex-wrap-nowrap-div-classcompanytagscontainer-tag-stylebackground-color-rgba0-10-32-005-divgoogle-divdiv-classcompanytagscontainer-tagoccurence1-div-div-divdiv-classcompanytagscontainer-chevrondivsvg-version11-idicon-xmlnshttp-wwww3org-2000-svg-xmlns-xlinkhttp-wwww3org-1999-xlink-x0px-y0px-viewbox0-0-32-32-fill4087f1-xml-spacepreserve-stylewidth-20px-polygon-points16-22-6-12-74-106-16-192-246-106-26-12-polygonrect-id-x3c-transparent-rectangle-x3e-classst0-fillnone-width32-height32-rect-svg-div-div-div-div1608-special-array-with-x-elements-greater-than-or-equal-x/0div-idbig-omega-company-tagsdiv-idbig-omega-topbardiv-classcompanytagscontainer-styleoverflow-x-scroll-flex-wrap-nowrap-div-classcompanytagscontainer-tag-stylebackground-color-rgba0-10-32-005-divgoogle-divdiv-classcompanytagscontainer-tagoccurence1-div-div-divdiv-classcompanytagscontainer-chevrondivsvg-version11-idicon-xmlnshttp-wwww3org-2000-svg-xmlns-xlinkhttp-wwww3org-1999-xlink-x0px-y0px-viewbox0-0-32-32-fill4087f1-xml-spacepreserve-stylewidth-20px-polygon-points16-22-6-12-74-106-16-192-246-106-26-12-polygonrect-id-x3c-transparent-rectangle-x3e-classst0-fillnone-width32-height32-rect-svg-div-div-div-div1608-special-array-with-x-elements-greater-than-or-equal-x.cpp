class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                continue;
            
            if(nums[i]==n-i)
            {
                if(i==0)
                    return nums[i];
                else if(i-1>=0 && nums[i]!=nums[i-1])
                    return nums[i];
            }
            
            if(nums[i]>n-i && ((i-1>=0 && nums[i-1]<n-i)||(i-1<0)))
                return n-i;
        }
        
        return -1;
    }
};