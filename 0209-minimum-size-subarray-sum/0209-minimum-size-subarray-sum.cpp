class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int i=-1;
        int j=-1;
        int sum=0;
        int ans=1e9;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1)
            {
                flag1=1;
                i++;
                sum+=nums[i];
                if(sum>=target)
                    break;
            }
            
            while(j<i)
            {
                if(sum>=target)
                {
                    ans=min(ans,i-j);
                }
                flag2=1;
                j++;
                sum-=nums[j];
                if(sum<target)
                    break;
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        if(ans==1e9)
            return 0;
        
        return ans;
        
    }
};