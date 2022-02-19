class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            ans.push_back(nums[i]+nums[n-i-1]);
        }
        
        return *max_element(ans.begin(),ans.end());
        
    }
};