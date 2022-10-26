class Solution {
public:
    
//     int solve(int n,int copy,int s,int flag,vector<vector<vector<int>>> &dp)
//     {
//        if(s==n)
//         {
//             return 1;
//         }
        
//         if(s>n)
//             return 1e8;
        
//         if(dp[copy][s][flag]!=-1)
//             return dp[copy][s][flag];
        
//         int c=0;
//         int p=0;
        
//         if(flag==0)
//             return dp[copy][s][flag]=1+solve(n,s,s,1,dp);
//         else
//             return dp[copy][s][flag]=1+min(solve(n,copy,s+copy,0,dp),solve(n,copy,s+copy,1,dp));
        
//     }
    
    int minSteps(int n) {
        
//         int s=1;
//         int copy=0;
//         int flag=0;
        
//         vector<int> prime(1001,1);
//         prime[0]=0;
//         prime[1]=0;
        
//         for(int i=2;i<1001;i++)
//         {
//             if(prime[i]==1)
//             {
//                 for(int j=2*i;j<1001;j+=i)
//                 {
//                     prime[j]=0;
//                 }
//             }
//         }
        
//         if(prime[n]==1)
//             return n;
        
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (n+1,vector<int>(2,-1)));
//         return solve(n,copy,s,flag,dp)-1;
        
        int ans=0;
        
        for(int i=2;i*i<=n;)
        {
            if(n%i==0)
            {
                ans+=i;
                n=n/i;
            }
            else
            {
                i++;
            }
        }
        
        if(n!=1)
            ans+=n;
        
        return ans;
    }
};



















