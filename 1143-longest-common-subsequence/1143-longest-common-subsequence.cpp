class Solution {
private:
    int check(vector<vector<int>> &dp,string &text1,string &text2,int n,int m,int ind1,int ind2)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(text1[ind1]==text2[ind2])
            return dp[ind1][ind2]=1+check(dp,text1,text2,n,m,ind1-1,ind2-1);
        return dp[ind1][ind2]=max(check(dp,text1,text2,n,m,ind1-1,ind2),check(dp,text1,text2,n,m,ind1,ind2-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
       int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return check(dp,text1,text2,n,m,n-1,m-1);
        
    }
};