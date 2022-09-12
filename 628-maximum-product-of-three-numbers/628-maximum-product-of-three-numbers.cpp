class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int maxi1=nums[n-1];
        int maxi2=nums[n-2];
        int maxi3=nums[n-3];
        
        int mini1=nums[0];
        int mini2=nums[1];
        int mini3=nums[2];
        
        
        vector<int> temp;
        temp.push_back(maxi1*maxi2*maxi3);
        temp.push_back(maxi1*mini1*mini2);
        temp.push_back(mini1*mini2*mini3);
        
        
        return *max_element(temp.begin(),temp.end());
    }
};