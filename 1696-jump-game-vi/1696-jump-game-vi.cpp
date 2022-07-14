class Solution {
private:
    int check(vector<int> &dp,vector<int> &nums,int n,int k,int ind)
    {
        if(ind==0)
        {
            return nums[ind];
        }
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int maxi=-1e8;
        for(int i=1;i<=k;i++)
        {
            if(ind-i<0)
                break;
            else
            {
                maxi=max(maxi,nums[ind]+check(dp,nums,n,k,ind-i));
            }
            
        }
        
        return dp[ind]=maxi;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        
        vector<int> dp(n,0);
        dp[0]=nums[0];
        
        multiset<int> st;
        st.insert(nums[0]);
        
        for(int i=1;i<n;i++)
        {
             if(i>k)
                 st.erase(st.find(dp[i-k-1]));
             dp[i]=*(--st.end())+nums[i];
             st.insert(dp[i]);
        }
        
        return dp[n-1];
    }
};