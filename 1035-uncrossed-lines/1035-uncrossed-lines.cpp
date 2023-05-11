class Solution {
public:
    
    int solve(vector<int> &nums1,int ind1,vector<int> &nums2,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(nums1[ind1]==nums2[ind2])
        {
            return dp[ind1][ind2]=1+solve(nums1,ind1-1,nums2,ind2-1,dp);
        }
        else
        {
            return dp[ind1][ind2]=max(solve(nums1,ind1-1,nums2,ind2,dp),solve(nums1,ind1,nums2,ind2-1,dp));
        }
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        
        return solve(nums1,n1-1,nums2,n2-1,dp);
        
    }
};