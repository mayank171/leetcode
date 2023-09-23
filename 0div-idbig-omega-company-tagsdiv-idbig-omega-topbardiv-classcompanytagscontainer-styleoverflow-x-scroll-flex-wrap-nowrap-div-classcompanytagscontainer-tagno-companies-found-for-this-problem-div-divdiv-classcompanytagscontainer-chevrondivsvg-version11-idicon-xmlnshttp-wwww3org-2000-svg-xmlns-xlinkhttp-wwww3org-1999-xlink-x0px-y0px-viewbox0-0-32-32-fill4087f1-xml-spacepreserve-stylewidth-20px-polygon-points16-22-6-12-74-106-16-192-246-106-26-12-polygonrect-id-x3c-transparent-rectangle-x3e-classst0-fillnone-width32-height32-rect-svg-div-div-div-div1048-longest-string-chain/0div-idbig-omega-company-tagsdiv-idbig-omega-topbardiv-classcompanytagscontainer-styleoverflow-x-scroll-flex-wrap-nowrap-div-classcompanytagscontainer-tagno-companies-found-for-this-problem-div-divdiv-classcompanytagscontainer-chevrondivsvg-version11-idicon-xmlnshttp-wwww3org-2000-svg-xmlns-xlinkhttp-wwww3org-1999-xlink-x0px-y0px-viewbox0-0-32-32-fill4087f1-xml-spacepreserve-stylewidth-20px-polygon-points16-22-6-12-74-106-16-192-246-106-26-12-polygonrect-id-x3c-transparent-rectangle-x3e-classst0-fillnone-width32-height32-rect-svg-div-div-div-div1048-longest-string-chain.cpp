class Solution {
public:
    
    static bool comp(string &a,string &b)
    {
        if(a.length()<b.length())
            return true;
        return false;
    }
    
    int solve(vector<string> &words,int n,int ind,int prev,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        
        if(dp[ind][prev]!=-1)
            return dp[ind][prev];

        string s=words[prev];
        if(words[ind].length()-1==s.length())
        {
            int flag=0;
            int l1=words[ind].length();
            int l2=l1-1;
            int i=0;
            int j=0;
            while(i<l1 && j<l2)
            {
                if(words[ind][i]!=s[j])
                {
                    flag++;
                    i++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            
            if(flag==0)
                flag=1;
            
            if(flag==1)
            {
                return dp[ind][prev]=max(1+solve(words,n,ind+1,ind,dp),solve(words,n,ind+1,prev,dp));
            }
            else
            {
                return dp[ind][prev]=solve(words,n,ind+1,prev,dp);
            }
        }
        else
        {
            return dp[ind][prev]=solve(words,n,ind+1,prev,dp);
        }
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        // for(auto &it:words)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        int n=words.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1+solve(words,n,i+1,i,dp);
        }
        
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i][i]);
        }
        
        return ans;
    }
};