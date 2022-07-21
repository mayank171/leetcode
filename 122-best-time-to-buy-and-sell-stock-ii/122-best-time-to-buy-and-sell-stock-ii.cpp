class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
//         vector<vector<int>> dp(n+1,vector<int>(2,0));
        
//         dp[n][0]=dp[n][1]=0;
        
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=0;j<2;j++)
//             {
//                 int profit=0;
//                 if(j)
//                 {
//                     int a=-prices[i]+dp[i+1][0];
//                     int b=0+dp[i+1][1];
//                     if(a>b)
//                         profit=a;
//                     else
//                         profit=b;
//                 }
//                 else
//                 {
//                     int a=prices[i]+dp[i+1][1];
//                     int b=0+dp[i+1][0];
//                     if(a>b)
//                         profit=a;
//                     else
//                         profit=b;
//                 }
//                 dp[i][j]=profit;
//             }
//         }
        
//         return dp[0][1];
        
        vector<int> dp(n+1,0);
        int ahead=0;
        int back=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                int profit=0;
                if(j)
                {
                    profit=max(-1*prices[i]+ahead,0+back);
                }
                else
                {
                    profit=max(prices[i]+back,ahead);
                }
                
                if(j==0)
                    ahead=profit;
                else
                    back=profit;
            }
        }
        cout<<ahead<<" "<<back<<endl;
        return  back;
    }
};