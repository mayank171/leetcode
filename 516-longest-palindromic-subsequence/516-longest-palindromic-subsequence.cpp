class Solution {
public:
    int check(vector<vector<int>> &dp,string &str1,string &str2,int n,int m,int ind1,int ind2)
    {
        if(ind1<0 || ind2<0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(str1[ind1]==str2[ind2])
            return dp[ind1][ind2]=1+check(dp,str1,str2,n,m,ind1-1,ind2-1);
        return dp[ind1][ind2]=max(check(dp,str1,str2,n,m,ind1-1,ind2),check(dp,str1,str2,n,m,ind1,ind2-1));
    }
    
    int longestPalindromeSubseq(string s) {
        
        string str1=s;
        reverse(s.begin(),s.end());
        string str2=s;
        
        int n=str1.length();
        int m=str2.length();
        
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return check(dp,str1,str2,n,m,n-1,m-1);
        
    }
};