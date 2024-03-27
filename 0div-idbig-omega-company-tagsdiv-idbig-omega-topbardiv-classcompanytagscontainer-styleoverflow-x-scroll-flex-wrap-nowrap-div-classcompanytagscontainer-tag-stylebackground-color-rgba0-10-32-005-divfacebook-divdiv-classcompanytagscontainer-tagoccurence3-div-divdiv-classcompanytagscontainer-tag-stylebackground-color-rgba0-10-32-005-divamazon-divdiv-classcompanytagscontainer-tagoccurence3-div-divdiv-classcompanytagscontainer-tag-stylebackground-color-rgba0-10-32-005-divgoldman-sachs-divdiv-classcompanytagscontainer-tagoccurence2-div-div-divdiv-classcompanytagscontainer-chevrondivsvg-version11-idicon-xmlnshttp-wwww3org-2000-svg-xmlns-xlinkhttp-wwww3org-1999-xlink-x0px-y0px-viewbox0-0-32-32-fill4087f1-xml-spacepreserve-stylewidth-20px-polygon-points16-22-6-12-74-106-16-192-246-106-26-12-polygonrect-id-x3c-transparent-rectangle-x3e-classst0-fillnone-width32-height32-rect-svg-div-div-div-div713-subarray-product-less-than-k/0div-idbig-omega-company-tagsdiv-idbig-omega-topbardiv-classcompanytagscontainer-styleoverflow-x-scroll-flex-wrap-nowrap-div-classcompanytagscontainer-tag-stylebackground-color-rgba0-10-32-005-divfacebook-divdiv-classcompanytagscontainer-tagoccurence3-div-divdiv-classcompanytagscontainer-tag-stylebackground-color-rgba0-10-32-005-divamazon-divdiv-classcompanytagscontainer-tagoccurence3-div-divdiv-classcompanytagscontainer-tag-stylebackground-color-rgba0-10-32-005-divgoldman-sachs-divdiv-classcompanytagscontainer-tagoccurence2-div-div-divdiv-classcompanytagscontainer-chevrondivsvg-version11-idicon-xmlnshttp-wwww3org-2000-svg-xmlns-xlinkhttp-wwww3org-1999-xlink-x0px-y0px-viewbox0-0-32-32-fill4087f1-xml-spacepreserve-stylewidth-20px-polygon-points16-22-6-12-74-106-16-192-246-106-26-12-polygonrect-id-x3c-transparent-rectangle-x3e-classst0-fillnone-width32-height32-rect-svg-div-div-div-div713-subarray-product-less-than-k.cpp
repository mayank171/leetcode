class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
       //   10 5 2 6
       //      |   |
        
        int i=-1;
        int j=-1;
        int n=nums.size();
        
        int prod=1;
        int ans=0;
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1)
            {
                flag1=1;
                i++;
                prod*=nums[i];
                
                if(prod>=k)
                    break;
            }
            
            while(j<i && prod>=k)
            {
                flag2=1;
                ans+=(i-j)-1;
                j++;
                prod/=nums[j];
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        int x=i-j;
        
        ans+=(x*(x+1))/2;
        
        return ans;
    }
};