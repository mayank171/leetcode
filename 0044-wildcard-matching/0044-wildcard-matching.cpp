class Solution {
public:
    
    int solve(string &s1,string &s2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0 && ind2<0)
            return 1;
        
        if(ind1<0)
        {
            int i=0;
            while(i<=ind2)
            {
                if(s2[i]!='*')
                    return 0;
                i++;
            }
            return 1;
        }
            
        if(ind2<0 && ind1>=0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2])
        {
            return dp[ind1][ind2]=solve(s1,s2,ind1-1,ind2-1,dp);
        }
        else if(s2[ind2]=='?')
        {
            return dp[ind1][ind2]=solve(s1,s2,ind1-1,ind2-1,dp);
        }
        else if(s2[ind2]=='*')
        {
            return dp[ind1][ind2]=solve(s1,s2,ind1-1,ind2,dp)|solve(s1,s2,ind1,ind2-1,dp);
        }
        
        return dp[ind1][ind2]=0;
    }
    
    bool isMatch(string s, string p) {
        
        int n1=s.length();
        int n2=p.length();
        
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        
        return solve(s,p,n1-1,n2-1,dp);
        
    }
};