class Solution {

private:
    int check(int n,vector<int> &sq,vector<int> &dp)
    {
        //cout<<n<<endl;
        if(n==0)
            return 0;
        if(n==1)
        {
            return 1;
        }
        
        if(dp[n]!=-1)
            return dp[n];
        
        int mini=1e8;
        for(int i=0;i<100;i++)
        {
            if(n-pow(sq[i],2)<0)
                break;
            mini=min(mini,check(n-pow(sq[i],2),sq,dp));
        }
        
        return dp[n]=1+mini;
    }
    
public:
    
    int numSquares(int n) {
        
        vector<int> sq;
        for(int i=0;i<100;i++)
            sq.push_back(i+1);
        
        vector<int> dp(n+1,0);
        
        //int ans=check(n,sq,dp);
        
        //return ans;
        
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<n+1;i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<101;j++)
            {
                if(i-pow(j+1,2)<0)
                    break;
                mini=min(mini,1+dp[i-pow(j+1,2)]);
            }
            dp[i]=mini;
        }
        
        return dp[n];
    }
};