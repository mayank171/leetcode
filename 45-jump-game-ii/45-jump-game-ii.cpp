class Solution {
public:
    int jump(vector<int>& nums) {
        
        int cur_reach=0;
        int cur_max=0;
        int jumps=0;
        int n=nums.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(i+nums[i]>cur_max)
            {
                cur_max=i+nums[i];
            }
            
            if(i==cur_reach)
            {
                jumps++;
                cur_reach=cur_max;
            }
        }
        
        return jumps;
        
    }
};