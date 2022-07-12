class Solution {
private:
    int check(string &s1,string &s2,int n,vector<vector<int>> &dp,int ind1,int ind2)
    {
        if(ind1<0 || ind2<0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2])
            return dp[ind1][ind2]=1+check(s1,s2,n,dp,ind1-1,ind2-1);
        return dp[ind1][ind2]=max(check(s1,s2,n,dp,ind1-1,ind2),check(s1,s2,n,dp,ind1,ind2-1));
    }
public:
    int minInsertions(string s) {
        
        int n=s.length();
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return n-check(s1,s2,n,dp,n-1,n-1);
        
    }
};