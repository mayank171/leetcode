class Solution {
public:
    
    int solve(int n,vector<int> &temp,int ind,vector<int> &dp)
    {
        if(n<0)
            return 1e9;
        
        if(n==0)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int mini=1e9;
        for(int i=ind;i<99;i++)
        {
            if(n<temp[i]*temp[i])
                break;
            mini=min(mini,1+solve(n-temp[i]*temp[i],temp,i,dp));
        }
        
        return dp[n]=mini;
    }
    
    int numSquares(int n) {
        
        vector<int> temp;
        
        int p=sqrt(1e4+10);
        
        for(int i=1;i<p;i++)
        {
            temp.push_back(i);
        }
        
        vector<int> dp(n+1,-1);
        
        cout<<temp.size()<<endl;
        
        return solve(n,temp,0,dp);
        
    }
};