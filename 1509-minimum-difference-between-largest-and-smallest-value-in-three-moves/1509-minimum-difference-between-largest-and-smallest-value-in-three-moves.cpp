class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n<=3)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        int ans=nums[n-3-1]-nums[0];
        
        ans=min(ans,min(nums[n-3]-nums[1],nums[n-4]-nums[0]));
        
        for(int i=2;i<n-2;i++)
        {
            int x=nums[n-2]-nums[2];
            int y=nums[n-3]-nums[1];
            int z=nums[n-1]-nums[3];
            int w=nums[n-4]-nums[0];
            ans=min(ans,min(x,min(w,min(z,y))));
        }
        
        ans=min(ans,min(nums[n-2]-nums[2],nums[n-1]-nums[3]));
        
        return ans;
        
//         0,1,5,10,14
        
        // - --
        // -- -
        // ---
        //   ---
        
//         0,1,1,4,6,6,6
        
//         0,1,1,4,0,0,0
//         0,1,1,4,1,1,1
//         0,1,1,4,1,1,1   
//         4,4,4,4,6,6,6    
        
//         0,1,2,2,6,6,6,
//         6,6,6,2,6,6,6
//         0,1,2,2,2,2,2
    }
};