class Solution {
public:
    
    void solve(vector<int> &nums,int n,int ind,int &ans,int val)
    {
        if(ind==n)
        {
            ans+=val;
            return ;
        }
        
        val^=nums[ind];
        solve(nums,n,ind+1,ans,val);
        val^=nums[ind];
        solve(nums,n,ind+1,ans,val);
    }
    
    int subsetXORSum(vector<int>& nums) {
        
        int ans=0;
        int val=0;
        int n=nums.size();
        solve(nums,n,0,ans,val);
        
        return ans;
    }
};