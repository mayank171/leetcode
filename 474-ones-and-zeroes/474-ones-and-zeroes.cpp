class Solution {
private:
    
    int check(vector<pair<int,int>> &count,vector<string> &strs,int m,int n,int ind,int N,vector<vector<vector<int>>> &dp)
    {
        if(ind==N)
        {
            return 0;
        }
        
        if(dp[ind][m][n]!=-1)
            return dp[ind][m][n];
        
        int take=0;
        int notTake=0;
        
        if(m>=count[ind].first && n>=count[ind].second)
        {
            take=1+check(count,strs,m-count[ind].first,n-count[ind].second,ind+1,N,dp);
        }
        
        notTake=0+check(count,strs,m,n,ind+1,N,dp);
        
        return dp[ind][m][n]=max(take,notTake);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
       int N=strs.size();
        vector<pair<int,int>> count(N);
        
        vector<vector<vector<int>>> dp(N,vector<vector<int>> (m+1,vector<int>(n+1,-1)));
        
        for(int i=0;i<N;i++)
        {
            int l=strs[i].length();
            int zero=0;
            int one=0;
            for(int j=0;j<l;j++)
            {
                if(strs[i][j]=='0')
                    zero++;
                else
                    one++;
            }
            count[i]={zero,one};
        }
        
        return check(count,strs,m,n,0,N,dp);
        
    }
};