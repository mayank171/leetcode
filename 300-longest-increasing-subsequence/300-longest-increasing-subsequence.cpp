class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            int size=ans.size();
            
            if(size==0)
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int ind=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
               // cout<<ind<<endl;
                if(ind==size)
                {
                    ans.push_back(nums[i]);
                }
                else if(ind>0 && ans[ind-1]==nums[i])
                    continue;
                else 
                    ans[ind]=nums[i];
            }
        }
        
        return ans.size();
        
    }
};