class Solution {

private:
    
    int check(int ind,vector<int> &nums,vector<int> &dp)
    {
        if(ind==nums.size()-1)
        {
            return dp[ind]=nums[ind];
        }
        
        if(ind>nums.size()-1)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int sum1=0;
        int sum2=0;
        
        sum1=nums[ind]+check((ind+2),nums,dp);
        
        sum2=check((ind+1),nums,dp);
        
        
        return dp[ind]=max(sum1,sum2);
    }
    
    int check1(int ind,vector<int> &nums,vector<int> &dp)
    {
        if(ind==nums.size()-2)
        {
            return dp[ind]=nums[ind];
        }
        
        if(ind>nums.size()-2)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int sum1=0;
        int sum2=0;
        
        sum1=nums[ind]+check1((ind+2),nums,dp);
        
        sum2=check1((ind+1),nums,dp);
        
        return dp[ind]=max(sum1,sum2);
        
    }
      
    
    
public:
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
        {
            return nums[0];
        }
        
        vector<int> dp(n,-1);
        
        int ind=1;
        
        check(ind,nums,dp);
        
        vector<int> dp2(n,-1);
        
        int ind1=0;
        
        check1(ind1,nums,dp2);
        
        
        
        for(auto &it:dp)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        for(auto &it:dp2)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        int maxi1=*max_element(dp.begin(),dp.end());
        int maxi2=*max_element(dp2.begin(),dp2.end());
        
        
        return max(maxi1,maxi2);
        
    }
};