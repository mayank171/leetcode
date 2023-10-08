class Solution {
public:
    
    int solve(vector<int> &nums1,int ind1,vector<int> &nums2,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
        {
            return -1e5;
        }
        
        if(dp[ind1][ind2]!=-1e5)
            return dp[ind1][ind2];
        
        int take=-1e5;
        int nottake=-1e5;
        
        take=nums1[ind1]*nums2[ind2]+max(0,solve(nums1,ind1-1,nums2,ind2-1,dp));
        nottake=max(solve(nums1,ind1-1,nums2,ind2,dp),solve(nums1,ind1,nums2,ind2-1,dp));
        return dp[ind1][ind2]=max(take,nottake);
        
        
//         if(ind1-1>=0)
//             
//         else
//             return dp[ind1][ind2]=take;
        
//         if(ind2-1>=0)
//             nottake2=solve(nums1,ind1,nums2,ind2-1,dp);
//         else
//             return dp[ind1][ind2]=max(take,nottake1);
        
      //  return dp[ind1][ind2]=max(take,max(nottake1,nottake2));
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        vector<vector<int>> dp(n1,vector<int>(n2,-1e5));
        
        return solve(nums1,n1-1,nums2,n2-1,dp);
    }
};