class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int reachable=0;
        for(int i=0;i<n;i++)
        {
            if(reachable<i)
            {
                return false;
            }
            else if(nums[i]+i>reachable)
                reachable=nums[i]+i;
            
        }
        
        return true;
        
    }
};