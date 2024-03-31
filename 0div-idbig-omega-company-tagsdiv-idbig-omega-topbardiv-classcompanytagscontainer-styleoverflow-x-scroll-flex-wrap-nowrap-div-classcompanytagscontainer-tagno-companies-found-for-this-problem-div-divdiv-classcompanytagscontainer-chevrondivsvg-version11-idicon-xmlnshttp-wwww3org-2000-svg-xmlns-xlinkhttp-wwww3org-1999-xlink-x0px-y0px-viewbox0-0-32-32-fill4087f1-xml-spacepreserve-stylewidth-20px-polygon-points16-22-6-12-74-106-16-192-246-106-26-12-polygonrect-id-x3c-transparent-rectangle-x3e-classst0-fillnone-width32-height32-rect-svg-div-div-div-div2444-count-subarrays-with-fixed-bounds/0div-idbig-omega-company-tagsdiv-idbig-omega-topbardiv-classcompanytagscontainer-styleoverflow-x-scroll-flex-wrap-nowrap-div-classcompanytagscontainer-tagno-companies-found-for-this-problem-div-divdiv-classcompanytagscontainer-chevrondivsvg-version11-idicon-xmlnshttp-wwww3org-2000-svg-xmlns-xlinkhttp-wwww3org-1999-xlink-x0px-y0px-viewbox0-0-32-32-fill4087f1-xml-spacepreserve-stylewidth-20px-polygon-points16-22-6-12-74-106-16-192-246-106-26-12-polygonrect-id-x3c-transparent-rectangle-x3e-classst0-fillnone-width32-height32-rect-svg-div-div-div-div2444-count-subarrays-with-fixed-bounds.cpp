class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int minKPos=-1;
        int maxKPos=-1;
        int culp=-1;
        
        int n=nums.size();
        long ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<minK || nums[i]>maxK)
            {
                culp=i;
            }
            
            if(nums[i]==minK)
            {
                minKPos=i;
            }
            
            if(nums[i]==maxK)
            {
                maxKPos=i;
            }
            
            long smaller=min(minKPos,maxKPos);
            ans+=smaller-culp<=0?0:smaller-culp;
        }
        
        return ans;
    }
};