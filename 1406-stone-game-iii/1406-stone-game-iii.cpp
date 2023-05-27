class Solution {
public:
    
    int solve(vector<int> &stones,int n,int ind,int flag,vector<vector<int>> &dp)
    {
        if(ind>=n)
            return 0;
        
        if(dp[ind][flag]!=-1)
            return dp[ind][flag];
        
        if(flag==0)
        {
            int maxi=-1e9;
            int sum=0;
            for(int x=0;x<3 && ind+x<n;x++)
            {
                sum+=stones[ind+x];
                maxi=max(maxi,sum+solve(stones,n,ind+x+1,1,dp));
            }
            
            return dp[ind][flag]=maxi;
        }    
        else
        {
            int mini=1e9;
            int sum=0;
            for(int x=0;x<3 && ind+x<n;x++)
            {
                sum+=stones[ind+x];
                mini=min(mini,solve(stones,n,ind+x+1,0,dp));
            }
            
            return dp[ind][flag]=mini;
        }
    }

    
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n=stoneValue.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        int alice=solve(stoneValue,n,0,0,dp);
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=stoneValue[i];
        }
        
        int bob=sum-alice;
        
        cout<<alice<<" "<<bob<<endl;
        
        if(alice>bob)
            return "Alice";
        else if(bob>alice)
            return "Bob";
        return "Tie";
    }
};