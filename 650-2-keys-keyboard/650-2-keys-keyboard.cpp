class Solution {
public:
    int check(int n,vector<int> &dp)
    {
        if(n<=4)
            return dp[n]=n;
        
        if(dp[n]!=-1)
            return dp[n];
        
        set<int> st;
        st.insert(1);
        
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
                st.insert(i);
        }
        
        if(*(--st.end())==1)
            return dp[n]=n;
        else
        {
            return dp[n]=n/(*(--st.end()))+check(*(--st.end()),dp);
        }
    }
    int minSteps(int n) {
        
        if(n==1)
            return 0;
        vector<int> dp(n+1,-1);
        
        
        
        return check(n,dp);
    }
};