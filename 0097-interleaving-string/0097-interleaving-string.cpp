class Solution {
public:
    
    bool solve(string &s1,int ind1,int l1,string &s2,int ind2,int l2,string &s3,int ind3,int l3,vector<vector<vector<int>>> &dp)
    {
        if(ind3==l3)
        {
            return true;
        }
        
        if(ind1==l1 && ind2==l2)
            return false;
        
        if(dp[ind1][ind2][ind3]!=-1)
            return dp[ind1][ind2][ind3];
        
        if(s3[ind3]==s1[ind1] && s3[ind3]==s2[ind2])
        {
            return dp[ind1][ind2][ind3]= solve(s1,ind1+1,l1,s2,ind2,l2,s3,ind3+1,l3,dp)|solve(s1,ind1,l1,s2,ind2+1,l2,s3,ind3+1,l3,dp);
        }
        else if(s3[ind3]==s1[ind1])
        {
            return dp[ind1][ind2][ind3]= solve(s1,ind1+1,l1,s2,ind2,l2,s3,ind3+1,l3,dp);
        }
        else if(s3[ind3]==s2[ind2])
        {
            return dp[ind1][ind2][ind3]= solve(s1,ind1,l1,s2,ind2+1,l2,s3,ind3+1,l3,dp);
        }
        else
            return  dp[ind1][ind2][ind3]=false;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        
        if(l1+l2!=l3)
            return false;
        
        vector<vector<vector<int>>> dp(l1+1,vector<vector<int>> (l2+1,vector<int> (l3+1,-1)));
        
        return solve(s1,0,l1,s2,0,l2,s3,0,l3,dp);
    }
};