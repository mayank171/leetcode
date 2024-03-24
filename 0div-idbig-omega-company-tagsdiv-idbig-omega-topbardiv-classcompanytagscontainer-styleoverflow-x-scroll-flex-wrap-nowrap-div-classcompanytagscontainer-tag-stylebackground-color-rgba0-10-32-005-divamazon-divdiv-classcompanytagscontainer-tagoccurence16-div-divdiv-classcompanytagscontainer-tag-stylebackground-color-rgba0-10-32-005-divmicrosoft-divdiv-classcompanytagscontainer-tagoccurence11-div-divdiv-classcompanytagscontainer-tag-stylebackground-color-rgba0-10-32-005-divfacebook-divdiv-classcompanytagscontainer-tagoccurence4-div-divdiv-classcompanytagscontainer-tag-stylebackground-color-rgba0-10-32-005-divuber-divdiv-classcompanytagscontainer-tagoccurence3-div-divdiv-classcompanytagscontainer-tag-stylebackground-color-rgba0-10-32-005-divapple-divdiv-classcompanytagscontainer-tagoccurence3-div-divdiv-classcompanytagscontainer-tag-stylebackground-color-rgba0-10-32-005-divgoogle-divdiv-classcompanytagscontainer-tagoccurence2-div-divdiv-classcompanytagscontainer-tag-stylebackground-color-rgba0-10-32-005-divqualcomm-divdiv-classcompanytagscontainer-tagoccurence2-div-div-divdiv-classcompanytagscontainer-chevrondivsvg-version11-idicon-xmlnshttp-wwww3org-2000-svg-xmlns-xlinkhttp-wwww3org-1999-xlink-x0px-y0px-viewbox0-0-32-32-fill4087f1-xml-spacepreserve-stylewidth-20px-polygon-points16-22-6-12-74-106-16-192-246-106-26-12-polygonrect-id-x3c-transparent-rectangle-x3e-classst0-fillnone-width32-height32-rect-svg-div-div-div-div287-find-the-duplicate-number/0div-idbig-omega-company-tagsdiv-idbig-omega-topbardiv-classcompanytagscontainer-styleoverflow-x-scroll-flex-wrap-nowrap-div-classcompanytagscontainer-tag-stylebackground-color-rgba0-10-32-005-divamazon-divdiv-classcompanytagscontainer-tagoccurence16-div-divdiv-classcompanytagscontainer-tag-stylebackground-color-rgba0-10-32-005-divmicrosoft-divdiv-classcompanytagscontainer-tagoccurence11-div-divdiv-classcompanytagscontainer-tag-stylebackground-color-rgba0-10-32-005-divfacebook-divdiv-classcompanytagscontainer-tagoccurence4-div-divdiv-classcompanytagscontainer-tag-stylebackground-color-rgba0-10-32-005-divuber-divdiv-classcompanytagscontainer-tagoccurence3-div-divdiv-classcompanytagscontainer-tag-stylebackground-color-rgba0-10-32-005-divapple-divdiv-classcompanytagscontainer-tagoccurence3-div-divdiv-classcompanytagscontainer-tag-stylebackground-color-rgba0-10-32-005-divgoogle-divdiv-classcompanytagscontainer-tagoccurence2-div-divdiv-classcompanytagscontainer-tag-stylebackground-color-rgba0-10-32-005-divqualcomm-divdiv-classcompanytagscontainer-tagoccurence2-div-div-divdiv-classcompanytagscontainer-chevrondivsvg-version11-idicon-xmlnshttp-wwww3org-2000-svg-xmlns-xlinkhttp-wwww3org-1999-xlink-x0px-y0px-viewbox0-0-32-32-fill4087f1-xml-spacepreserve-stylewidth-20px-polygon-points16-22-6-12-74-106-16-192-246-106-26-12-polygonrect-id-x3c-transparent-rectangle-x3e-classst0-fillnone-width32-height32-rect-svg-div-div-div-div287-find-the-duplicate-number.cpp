class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
//         s  1  3  2  4  4
//         f  3  4  4  4  4
            
        int slow=0;
        int fast=0;
        
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        
        fast=0;
        do
        {
            slow=nums[slow];
            fast=nums[fast];
        }while(slow!=fast);
        
        
        return slow;
    }
};