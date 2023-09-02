class Solution {
public:
    
    int solve(string &s,int ind,int n,string str,set<string> &st,vector<int> &dp)
    {
        if(ind>=n)
        {
            if(str.size()==0)
                return 0;
            return 1e8;
        }
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int mini=1e9;
        for(int i=ind;i<n;i++)
        {
            str+=s[i];
            
            
            if(st.find(str)!=st.end())
            {
                mini=min(mini,solve(s,i+1,n,"",st,dp));
            }
            else if(str.size()==1)
            {
                mini=min(mini,1+solve(s,i+1,n,"",st,dp));
            }
        }
        
        return dp[ind]=mini;
    }
    
    int minExtraChar(string s, vector<string>& dict) {
        
        set<string> st;
        for(auto &it:dict)
        {
            st.insert(it);
        }
        
        int n=s.length();
        
        string str="";
        multiset<char> temp;
        vector<int> dp(100,-1);
        return solve(s,0,n,str,st,dp);
    }
};