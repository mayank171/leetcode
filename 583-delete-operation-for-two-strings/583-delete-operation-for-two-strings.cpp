class Solution {
private:
    int check(string &s1,int n,string &s2,int m,vector<vector<int>> &dp,int ind1,int ind2)
    {
        if(ind1<0 || ind2<0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2])
            return dp[ind1][ind2]=1+check(s1,n,s2,m,dp,ind1-1,ind2-1);
        return dp[ind1][ind2]=max(check(s1,n,s2,m,dp,ind1-1,ind2),check(s1,n,s2,m,dp,ind1,ind2-1));
    }
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int x=check(word1,n,word2,m,dp,n-1,m-1);
        
        return (n-x+m-x);
    }
};