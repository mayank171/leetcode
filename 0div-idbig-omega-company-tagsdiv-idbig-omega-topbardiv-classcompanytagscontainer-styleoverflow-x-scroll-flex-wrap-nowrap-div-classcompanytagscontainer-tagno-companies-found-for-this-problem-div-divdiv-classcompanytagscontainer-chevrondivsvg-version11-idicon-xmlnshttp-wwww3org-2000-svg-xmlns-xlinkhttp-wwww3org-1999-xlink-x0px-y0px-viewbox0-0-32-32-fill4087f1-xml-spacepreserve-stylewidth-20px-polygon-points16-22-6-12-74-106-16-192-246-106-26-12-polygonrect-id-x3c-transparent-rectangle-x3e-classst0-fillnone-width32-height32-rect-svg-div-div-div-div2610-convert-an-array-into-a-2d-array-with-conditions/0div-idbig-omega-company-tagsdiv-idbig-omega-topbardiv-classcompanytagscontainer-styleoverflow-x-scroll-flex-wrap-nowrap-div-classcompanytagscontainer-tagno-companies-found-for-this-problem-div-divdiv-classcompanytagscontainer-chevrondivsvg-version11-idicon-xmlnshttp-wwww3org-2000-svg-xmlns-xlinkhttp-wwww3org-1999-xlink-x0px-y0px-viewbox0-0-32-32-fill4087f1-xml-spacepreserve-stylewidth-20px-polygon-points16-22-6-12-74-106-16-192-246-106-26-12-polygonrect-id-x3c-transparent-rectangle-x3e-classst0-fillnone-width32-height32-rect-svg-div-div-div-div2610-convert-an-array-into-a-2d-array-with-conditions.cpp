class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int maxi=1;
        int ct=1;
        int val=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                ct++;
            }
            else
            {
                maxi=max(maxi,ct);
                ct=1;
                val=nums[i];
            }
        }
        
        maxi=max(maxi,ct);
        
        vector<vector<int>> ans(maxi);
        int ind=0;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]!=nums[i-1])
            {
                ans[ind].push_back(nums[i]);
            }
            else if(i>0 && nums[i]==nums[i-1])
            {
                ind=(ind+1)%maxi;
                ans[ind].push_back(nums[i]);
            }
            else if(i==0)
            {
                ans[ind].push_back(nums[i]);
            }
        }
        
        return ans;
        
    }
};

















