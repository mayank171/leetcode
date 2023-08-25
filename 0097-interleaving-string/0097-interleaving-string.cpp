class Solution {
public:
    
    int solve(string &s1,int ind1,string &s2,int ind2,string &s3,int ind3,vector<vector<vector<int>>> &dp)
    {
       // cout<<ind1<<" "<<ind2<<" "<<ind3<<endl;
        if(ind1<0 && ind2<0)
        {
            if(ind3<0)
                return 1;
            return 0;
        }
        
        if(ind3<0)
        {
            if(ind1>=0 || ind2>=0)
                return 0;
        }
        
        if(dp[ind1+1][ind2+1][ind3+1]!=-1)
            return dp[ind1+1][ind2+1][ind3+1];
        
        if(ind1>=0 && ind2>=0 && s1[ind1]==s3[ind3] && s2[ind2]==s3[ind3])
        {
            return dp[ind1+1][ind2+1][ind3+1]=solve(s1,ind1-1,s2,ind2,s3,ind3-1,dp)|solve(s1,ind1,s2,ind2-1,s3,ind3-1,dp);
        }
        else if(ind1>=0 && s1[ind1]==s3[ind3])
        {
            return dp[ind1+1][ind2+1][ind3+1]=solve(s1,ind1-1,s2,ind2,s3,ind3-1,dp);
        }
        else if(ind2>=0 && s2[ind2]==s3[ind3])
        {
            return dp[ind1+1][ind2+1][ind3+1]=solve(s1,ind1,s2,ind2-1,s3,ind3-1,dp);    
        }
        
        return dp[ind1+1][ind2+1][ind3+1]=0;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int ind1=s1.length()-1;
        int ind2=s2.length()-1;
        int ind3=s3.length()-1;
        
        vector<vector<vector<int>>> dp(105,vector<vector<int>> (105,vector<int>(205,-1)));
        
        return solve(s1,ind1,s2,ind2,s3,ind3,dp);
    }
};