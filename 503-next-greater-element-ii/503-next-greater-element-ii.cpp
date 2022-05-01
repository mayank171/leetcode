class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        
        stack<int> stk;
        
        vector<int> ans(n,-1);
        
        for(int i=0;i<2*n;i++)
        {
            while(!stk.empty() && nums[stk.top()]<nums[i%n])
            {
                ans[stk.top()]=nums[i%n];
                stk.pop();
            }
            
            stk.push(i%n);
        }
        
        
        return ans;
            
        
    }
};