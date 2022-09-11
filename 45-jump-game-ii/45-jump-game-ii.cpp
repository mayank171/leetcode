class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int jumps=1;
        int curend=nums[0];
        int maxreach=nums[0];
        
        if(n==1)
            return 0;
        
        if(maxreach>=n-1)
            return jumps;
        
        for(int i=0;i<n;i++)
        {
            maxreach=max(maxreach,i+nums[i]);
            
            if(maxreach>=n-1)
                return 1+jumps;
            if(i==maxreach)
                break;
            if(i==curend)
            {
                jumps++;
                curend=maxreach;
            }
        }
        
        return 0;
        
    }
};