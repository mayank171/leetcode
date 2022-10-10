class Solution {
public:
    int jump(vector<int>& v) {
        
//         int n=nums.size();
//         int jumps=1;
//         int curend=nums[0];
//         int maxreach=nums[0];
        
//         if(n==1)
//             return 0;
        
//         if(maxreach>=n-1)
//             return jumps;
        
//         for(int i=0;i<n;i++)
//         {
//             maxreach=max(maxreach,i+nums[i]);
            
//             if(maxreach>=n-1)
//                 return 1+jumps;
//             if(i==maxreach)
//                 break;
//             if(i==curend)
//             {
//                 jumps++;
//                 curend=maxreach;
//             }
//         }
        
//         return 0;
        
        int n=v.size();
   
         vector<int> dp(n,1e9);
         dp[0]=0;
         
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<i;j++)
             {
                 if(j+v[j]>=i)
                 {
                     dp[i]=min(dp[i],dp[j]+1);
                 }
             }
         }
    
         if(dp[n-1]>=1e9)
             return -1;
         else
             return dp[n-1];
        
    }
};