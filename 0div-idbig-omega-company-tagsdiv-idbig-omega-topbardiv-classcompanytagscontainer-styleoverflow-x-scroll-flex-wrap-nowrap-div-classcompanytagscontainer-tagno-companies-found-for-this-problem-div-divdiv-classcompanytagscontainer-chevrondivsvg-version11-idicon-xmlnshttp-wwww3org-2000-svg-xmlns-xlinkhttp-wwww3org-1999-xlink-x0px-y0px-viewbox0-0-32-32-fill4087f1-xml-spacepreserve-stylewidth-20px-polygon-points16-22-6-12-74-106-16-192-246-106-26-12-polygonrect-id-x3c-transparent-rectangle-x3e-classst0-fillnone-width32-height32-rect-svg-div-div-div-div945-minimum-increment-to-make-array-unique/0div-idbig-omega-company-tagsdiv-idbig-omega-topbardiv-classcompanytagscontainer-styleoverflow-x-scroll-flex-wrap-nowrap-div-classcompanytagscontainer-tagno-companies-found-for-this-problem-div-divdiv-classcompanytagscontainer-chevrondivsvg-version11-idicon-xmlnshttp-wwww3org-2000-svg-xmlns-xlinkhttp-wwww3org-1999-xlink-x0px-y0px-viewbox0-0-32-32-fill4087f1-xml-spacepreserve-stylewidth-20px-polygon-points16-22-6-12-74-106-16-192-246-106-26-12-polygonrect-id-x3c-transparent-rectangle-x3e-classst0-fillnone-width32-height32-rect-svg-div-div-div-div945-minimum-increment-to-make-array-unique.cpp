class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
       // return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int ans=0;        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                ans+=abs(nums[i]-(nums[i-1]+1));
                nums[i]=nums[i-1]+1;
            
               // cout<<ans<<endl;
            }
        }
        
        return ans;
    }
};