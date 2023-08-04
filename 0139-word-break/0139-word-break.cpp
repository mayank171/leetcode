class Solution {
public:
    
    int solve(string &s,int n,int ind,vector<string> &wordDict,int size,set<string> &st,string temp,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(temp.size()==0)
                return 1;
            return 0;
        }
        
        if(dp[ind][temp.size()]!=-1)
            return dp[ind][temp.size()];

        temp+=s[ind];
        if(st.find(temp)!=st.end())
        {
            string temp1="";
            int take=solve(s,n,ind+1,wordDict,size,st,temp1,dp);
            int nottake=solve(s,n,ind+1,wordDict,size,st,temp,dp);
            temp.pop_back();
            return dp[ind][temp.size()]=take|nottake;
        }
        else
        {
            int ans= solve(s,n,ind+1,wordDict,size,st,temp,dp);
            temp.pop_back();
            return dp[ind][temp.size()]=ans;
        }
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        int size=wordDict.size();
        set<string> st;
        for(auto &it:wordDict)
            st.insert(it);
        
        string temp="";
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,n,0,wordDict,size,st,temp,dp);
    }
};