class Solution {
public:
    
    int solve(vector<vector<int>> &vp,int n,int ind,int lane,vector<vector<int>> &dp)
    {
       // cout<<ind<<" "<<lane<<endl;
        if(ind==n-1)
            return 0;
        
        if(dp[lane][ind]!=-1)
            return dp[lane][ind];
        
        if(lane==2)
        {
            int mini=1e9;
            int a=1e9,b=1e9,c=1e9;
            if(vp[1][ind+1]==0 && vp[1][ind]==0)
               a=1+solve(vp,n,ind+1,1,dp);
            if(vp[3][ind+1]==0 && vp[3][ind]==0)
               b=1+solve(vp,n,ind+1,3,dp);
            if(vp[2][ind+1]==0)
               c=solve(vp,n,ind+1,2,dp);
            
            return dp[lane][ind]=min(a,min(b,c));
        }
        else if(lane==1)
        {
            int mini=1e9;
            int a=1e9,b=1e9,c=1e9;
          //  cout<<"cdcdc";
            if(vp[2][ind+1]==0 && vp[2][ind]==0)
               a=1+solve(vp,n,ind+1,2,dp);
            if(vp[3][ind+1]==0 && vp[3][ind]==0)
               b=1+solve(vp,n,ind+1,3,dp);
            if(vp[1][ind+1]==0)
               c=solve(vp,n,ind+1,1,dp);
            
            return dp[lane][ind]=min(a,min(b,c));
        }
        else
        {
            int mini=1e9;
            int a=1e9,b=1e9,c=1e9;
            if(vp[2][ind+1]==0 && vp[2][ind]==0)
               a=1+solve(vp,n,ind+1,2,dp);
            if(vp[1][ind+1]==0 && vp[1][ind]==0)
               b=1+solve(vp,n,ind+1,1,dp);
            if(vp[3][ind+1]==0)
               c=solve(vp,n,ind+1,3,dp);
            
            return dp[lane][ind]=min(a,min(b,c));
        }
        
    }
    
    int minSideJumps(vector<int>& vp) {
        
        int n=vp.size();
        
        vector<vector<int>> temp(4,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            if(vp[i]>0)
               temp[vp[i]][i]=-1;
        }
        
        vector<vector<int>> dp(4,vector<int>(n+1,-1));
        
        return solve(temp,n,0,2,dp);
    }
};