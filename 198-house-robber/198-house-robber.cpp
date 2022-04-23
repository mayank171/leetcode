class Solution {
private:
    
//     int check(vector<int> &nums,vector<int> &dp,int ind)
//     {
//         if(ind==0)
//         {
//             return dp[ind]=nums[ind];
//         }
        
//         if(ind<0)
//         {
//             return 0;
//         }
        
//         if(dp[ind]!=-1)
//             return dp[ind];
        
//         int sum1=nums[ind]+check(nums,dp,ind-2);
//         int sum2=0+check(nums,dp,ind-1);
        
//         return dp[ind]=max(sum1,sum2);
//     }
    
public:
    int rob(vector<int>& nums) {
        
//         int n=nums.size();
        
//         vector<int> dp(n,-1);
        
//         int ind=n-1;
        
//         check(nums,dp,ind);
        
//         for(auto &it:dp)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         return dp[n-1];
        
        
//         int n=nums.size();
        
//         vector<int> dp(n,-1);
        
//         dp[0]=nums[0];
//         int neg=0;
        
//         for(int i=1;i<n;i++)
//         {
//             int take=0;
//             int not_take=0;
//             if(i-2<0)
//             {
//                 take=nums[i]+neg;
//             }
//             else
//             {
//                 take=nums[i]+dp[i-2];
//             }
            
//             not_take=0+dp[i-1];
            
//             dp[i]=max(take,not_take);
            
           
            
//         }
        
//         return dp[n-1];
        
        
        int n=nums.size();
        
        int prev1=nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++)
        {
            int take=0;
            int not_take=0;
            
            if(i-2>=0)
            {
                take=nums[i]+prev2;
            }
            else
            {
                take=nums[i];
            }
            
            not_take=prev1;
            
            int cur=max(take,not_take);
            prev2=prev1;
            prev1=cur;
        }
        
        return max(prev1,prev2);
        
        
        
        
        
    }
};