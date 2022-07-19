class Solution {
public:
    int check(vector<string> &strs,int ind,int m,int n,vector<vector<vector<int>>> &dp)
    {
      //  cout<<m<<" "<<n<<" "<<ind<<endl;
        if(ind<0)
        {
            return 0;
        }
        if(m==0 && n==0)
            return 0;
        
        
        if(dp[ind][m][n]!=-1)
            return dp[ind][m][n];
        
        int l=strs[ind].size();
        int ct_1=0;int ct_0=0;
        
        for(int j=0;j<l;j++)
        {
            if(strs[ind][j]=='0')
                ct_0++;
            else
                ct_1++;
        }
        
        int pick=0;int notpick=0;
        
        if(ct_0<=m && ct_1<=n)
            pick=1+check(strs,ind-1,m-ct_0,n-ct_1,dp);
        notpick=0+check(strs,ind-1,m,n,dp);
        
       // cout<<ind<<" "<<max(pick,notpick)<<endl;
        
        return dp[ind][m][n]=max(pick,notpick);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
    
        int N=strs.size();
        
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        
        return check(strs,N-1,m,n,dp);
        
    }
};