class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        
        int i=0;
        int j=0;
        
        while(i<n && j<n)
        {
            if(nums[i]&1 && nums[j]%2==0)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]%2==0)
            {
                i++;
                j++;
            }
            else 
            {
                j++;
            }
        }
        
        return nums;
        
        
    }
};