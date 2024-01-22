class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n=nums.size();
        
        int xxor=0;
        for(int i=0;i<n;i++)
        {
            xxor^=nums[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            xxor^=i;
        }
        
        
        int val=-1;
        for(int i=0;i<n;i++)
        {
           
            if(nums[abs(nums[i])-1]<0)
            {
                val=abs(nums[i]);
                break;
            }
            else
            {
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            }
        }
        
        
        
        return {val,val^xxor};
    }
};