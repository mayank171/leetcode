class Solution {
public:
    
    int solve(vector<int> &piles,int ind,int n,int m,int flag,vector<vector<vector<int>>> &dp)
    {
       // cout<<ind<<" "<<flag<<endl;
        // if(m>n-ind)
        //     return 0;
        
        if(ind>=n)
        {
            return 0;
        }
        
        if(dp[ind][m][flag]!=-1)
            return dp[ind][m][flag];
        
        
        if(flag==0)
        {
            int ans=0;
            for(int x=1;x<=2*m;x++)
            {
                int sum=0;
                for(int k=ind;k<ind+x && k<n;k++)
                {
                    sum+=piles[k];
                }
        //        cout<<sum<<" "<<flag<<endl;
                
                ans=max(ans,sum+solve(piles,ind+x,n,max(x,m),1,dp));
            }    
            
            return dp[ind][m][flag]=ans;
        }
        else
        {
            int ans=1e9;
            for(int x=1;x<=2*m;x++)
            {
                int sum=0;
                for(int k=ind;k<ind+x && k<n;k++)
                {
                    sum+=piles[k];
                }
         //       cout<<sum<<" "<<flag<<endl;
                
                ans=min(ans,solve(piles,ind+x,n,max(x,m),0,dp));
            }
            return dp[ind][m][flag]=ans;
        }
//         for(int x=1;x<=2*m;x++)
//         {
//             int sum=0;
//             for(int k=ind;k<ind+x && k<n;k++)
//             {
//                 sum+=piles[k];
//             }
            
//             for(int y=1;y<=2*max(x,m);y++)
//             {
//                 ans=max(ans,sum+solve(piles,ind+x+y,n,max(y,max(x,m))));
//             }
//         }
        
        //return ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        
        int n=piles.size();
        int m=1;
        int flag=0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2*n,vector<int> (2,-1)));
        return solve(piles,0,n,m,flag,dp);
        
    }
};