class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        
        stack<int> stk;
        stk.push(0);
        
        vector<int> ans(n,-1);
        
        int ind=1;
        for(int i=1;i<n;i=(i+1)%n)
        {
            if(ind==2*n)
                break;
            
            while(!stk.empty() && nums[stk.top()]<nums[i])
            {
                if(ans[stk.top()]==-1)
                {
                    ans[stk.top()]=nums[i];
                }
                stk.pop();
            }
            
            stk.push(i);
            ind++;
        }
        
        
        
//         stack<int> stk1;
//         stk1.push(n-1);
//         for(int i=n-2;i>=0;i--)
//         {
//             while(!stk1.empty() && nums[stk1.top()]<nums[i])
//             {
//                 if(ans[stk1.top()]==-1)
//                 {
//                     ans[stk1.top()]=nums[i];
//                 }
//                 stk1.pop();
//             }
//             stk1.push(i);
//             ind++;
//         }
        
        
        return ans;
        
    }
};