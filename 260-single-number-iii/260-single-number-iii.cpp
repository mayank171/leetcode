class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int l=nums.size();
        
        vector<int> ans;
        
        for(int i=0;i<l;i++)
        {
            
            if(i==l-1)
            {
                ans.push_back(nums[i]);
                break;
            }
            
            if(nums[i]==nums[i+1])
            {
                i++;
            }
            else 
            {
                ans.push_back(nums[i]);
            }
            
            if(ans.size()==2)
            {
                break;
            }
            
        }
        
        return ans;
        
    }
};