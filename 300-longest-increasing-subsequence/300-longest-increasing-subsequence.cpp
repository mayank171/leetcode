class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
       int n=nums.size();
        
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            int sz=ans.size();
            if(nums[i]>ans[sz-1])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int ind=upper_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                if(ind==sz)
                    continue;
                else if(ind-1>=0 && ans[ind-1]==nums[i])
                    continue;
                else
                    ans[ind]=nums[i];
            }
        }
        
        for(auto &it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        return ans.size();
        
    }
};