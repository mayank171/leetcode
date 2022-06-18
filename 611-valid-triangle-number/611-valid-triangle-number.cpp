class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int ans=0;
        
        for(int i=2;i<n;i++)
        {
            int j=0;
            int k=i-1;
            
            while(j<k)
            {
                if(nums[j]+nums[k]>nums[i])
                {
                    ans+=k-j;
                    k--;
                    //break;
                }
                else
                {
                    j++;
                }
            }
            
        }
        
        return ans;
    }
};