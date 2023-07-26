class Solution {
public:
    
    int isPalindrome(string &s)
    {
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    
    int solve(string &s,int n,int ind,string &temp,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(temp.size()>0)
            {
                if(isPalindrome(temp))
                    return 1;
                return 1e5;
            }
            
            return 1e5;
        }
        
        if(dp[ind][temp.size()]<1e5)
            return dp[ind][temp.size()];
        
        int take=1e5;
        temp+=s[ind];
        take=solve(s,n,ind+1,temp,dp);
        temp.pop_back();
        
        int nottake=1e5;
        
        if(isPalindrome(temp))
        {
            string temp1="";
            temp1+=s[ind];
            nottake=1+solve(s,n,ind+1,temp1,dp);
        }
        
        int x=min(take,nottake);
        return dp[ind][temp.size()]=x;
    }
    
    int minCut(string s) {
        
        int n=s.length();
        string temp="";
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e5));
        return solve(s,n,0,temp,dp)-1;
    }
};