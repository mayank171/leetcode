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
        
        vector<int> dp(n+1,-1);
        
        return check(n,sq,dp);
        
    }
};