class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.length();
        if(n==0)
            return 0;
        vector<int> dp(n,0);
        
        map<int,int> mp;
        mp[0]=-1;
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                p--;
                if(p<0)
                {
                    p=0;
                    dp[i]=p;
                    mp[p]=i;
                }
                else if(mp.find(p)==mp.end())
                {
                    dp[i]=p;
                    mp[dp[i]]=i;
                }
                else
                {
                    dp[i]=(i-mp[p]); 
                }
            }
            else
            {
                p++;
                mp[p]=i;
            }
        }
        
        for(auto &it:dp)
            cout<<it<<" ";
        cout<<endl;
        
        return *max_element(dp.begin(),dp.end());
    }
    
    
    
    
    
    
};