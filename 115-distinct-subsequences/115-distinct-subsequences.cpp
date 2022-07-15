class Solution {
public:
    int mod=1e9+7;
    int check(string &s,string &t,int n,int m,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind2<0)
            return 1;
        if(ind1<0)
        {
            if(ind2<0)
                return 1;
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        int l=0,r=0;
        
        if(s[ind1]==t[ind2])
        {
            l=check(s,t,n,m,ind1-1,ind2-1,dp);
        }
        r=check(s,t,n,m,ind1-1,ind2,dp);
        
        return dp[ind1][ind2]=(l+r)%mod;
    }
    
    int numDistinct(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return check(s,t,n,m,n-1,m-1,dp);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         vector<int> front(m+1,0);
//         front[0]=1;
        
//         for(int i=1;i<n+1;i++)
//         {
// //             vector<int> cur(m+1,0);
// //             cur[0]=1;
//             for(int j=m;j>0;j--)
//             {
//                 int l=0;int r=0;
//                 if(s[i-1]==t[j-1])
//                     l=front[j-1];
//                 r=front[j];
//                 front[j]=(l+r)%mod;
//             }
//            // front=cur;
//         }
        
//         return front[m];
    
        
    }
};