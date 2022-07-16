class Solution {
public:
    int mod=1e9+7;
    int check(vector<vector<vector<int>>> &dp,int n,int m,int moves,int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=m)
            return 0;
        
        if((x==n-1 && y==0)||(x==n-1 && y==m-1))
            return 0;
     
        if(moves==0)
            return 1;
        
        if(dp[x][y][moves]!=-1)
            return dp[x][y][moves];
        
        int ct=0;
        
        // if(x-2>=0 && x-2<n && y-1>=0 && y-1<m)
            ct=(ct+check(dp,n,m,moves-1,x-2,y-1))%mod;
        
        // if(x-2>=0 && x-2<n && y+1>=0 && y+1<m)
            ct=(ct+check(dp,n,m,moves-1,x-2,y+1))%mod;
        
        // if(x+2>=0 && x+2<n && y-1>=0 && y-1<m)
            ct=(ct+check(dp,n,m,moves-1,x+2,y-1))%mod;
        
        // if(x+2>=0 && x+2<n && y+1>=0 && y+1<m)
            ct=(ct+check(dp,n,m,moves-1,x+2,y+1))%mod;
        
        // if(x-1>=0 && x-1<n && y-2>=0 && y-2<m)
            ct=(ct+check(dp,n,m,moves-1,x-1,y-2))%mod;
        
        // if(x+1>=0 && x+1<n && y-2>=0 && y-2<m)
            ct=(ct+check(dp,n,m,moves-1,x+1,y-2))%mod;
        
        // if(x-1>=0 && x-1<n && y+2>=0 && y+2<m)
            ct=(ct+check(dp,n,m,moves-1,x-1,y+2))%mod;
        
        // if(x-1>=0 && x-1<n && y+2>=0 && y+2<m)
            ct=(ct+check(dp,n,m,moves-1,x+1,y+2))%mod;
        
        return dp[x][y][moves]=ct;
    }
    
    
    int knightDialer(int n) {
        
        int N=4;
        int M=3;
        
        int ans=0;
        
        vector<vector<vector<int>>> dp(N,vector<vector<int>> (M,vector<int>(n,-1)));
        
        for(int i=3;i>=0;i--)
        {
            for(int j=2;j>=0;j--)
            {
                if((i==3 && j==0)||(i==3 && j==2))
                    continue;
                int x=check(dp,N,M,n-1,i,j);
                ans=(x+ans)%mod;
            }
        }
        
        return ans;
    }
};