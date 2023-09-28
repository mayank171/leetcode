class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int e=0;
        int o=0;
        int n=nums.size();
        
        while(e<n && o<n)
        {
            if(nums[e]%2!=0 && nums[o]%2!=0)
            {
                e++;
            }
            else if(nums[e]%2==0 && nums[o]%2==0)
            {
                o++;
            }
            else if(o<e && nums[e]%2==0)
            {
                swap(nums[e],nums[o]);
                o++;
            }
            else if(o>e && nums[o]%2!=0)
            {
                e++;
            }
        }
        
        return nums;
        
    }
};