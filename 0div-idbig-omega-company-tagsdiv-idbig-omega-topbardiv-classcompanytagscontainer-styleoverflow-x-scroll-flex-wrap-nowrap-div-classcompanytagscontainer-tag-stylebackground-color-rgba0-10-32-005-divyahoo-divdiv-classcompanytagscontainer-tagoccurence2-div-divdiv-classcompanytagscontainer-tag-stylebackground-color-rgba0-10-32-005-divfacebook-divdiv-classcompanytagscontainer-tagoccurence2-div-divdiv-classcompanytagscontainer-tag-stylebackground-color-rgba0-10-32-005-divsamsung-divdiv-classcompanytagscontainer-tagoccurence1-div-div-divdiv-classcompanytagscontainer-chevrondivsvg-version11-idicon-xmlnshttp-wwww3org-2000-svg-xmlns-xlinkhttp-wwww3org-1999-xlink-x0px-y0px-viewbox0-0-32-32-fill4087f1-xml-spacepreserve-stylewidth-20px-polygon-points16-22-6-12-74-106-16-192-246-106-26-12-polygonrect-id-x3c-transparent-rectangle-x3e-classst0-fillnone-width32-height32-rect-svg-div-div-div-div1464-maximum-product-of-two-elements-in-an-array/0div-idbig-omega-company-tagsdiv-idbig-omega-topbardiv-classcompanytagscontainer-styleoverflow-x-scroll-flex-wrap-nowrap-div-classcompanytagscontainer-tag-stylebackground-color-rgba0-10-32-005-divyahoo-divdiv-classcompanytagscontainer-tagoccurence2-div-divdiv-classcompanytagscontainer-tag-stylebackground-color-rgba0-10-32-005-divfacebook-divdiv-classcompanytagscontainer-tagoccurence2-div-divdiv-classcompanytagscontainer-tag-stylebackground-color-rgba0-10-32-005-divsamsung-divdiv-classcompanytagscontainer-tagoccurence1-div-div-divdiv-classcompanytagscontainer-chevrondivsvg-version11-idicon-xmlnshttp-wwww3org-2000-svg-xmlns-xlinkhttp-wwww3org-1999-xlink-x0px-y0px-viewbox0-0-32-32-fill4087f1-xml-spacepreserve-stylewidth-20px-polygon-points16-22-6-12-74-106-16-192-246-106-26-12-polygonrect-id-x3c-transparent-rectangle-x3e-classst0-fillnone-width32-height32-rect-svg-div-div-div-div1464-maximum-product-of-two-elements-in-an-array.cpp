class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi1=-1;
        int maxi2=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(maxi1<nums[i])
            {
                maxi2=maxi1;
                maxi1=nums[i];
            }
            else if(maxi2<nums[i])
            {
                maxi2=nums[i];
            }
        }
        
        return (maxi1-1)*(maxi2-1);
    }
};