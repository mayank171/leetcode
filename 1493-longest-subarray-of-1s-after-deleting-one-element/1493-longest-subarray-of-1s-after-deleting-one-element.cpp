class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        int i=-1;
        int j=-1;
        int ind=-1;
        int ans=0;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1)
            {
                flag1=1;
                i++;
                if(nums[i]==0 && ind==-1)
                {
                    ind=i;
                }
                else if(nums[i]==0 && ind!=-1)
                {
                    i--;
                    break;
                }
            }
            
            while(j<i)
            {
                flag2=1;    
               ans=max(ans,i-j-1);
                j++;
                if(j==ind)
                {
                    ind=-1;
                    break;
                }
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};