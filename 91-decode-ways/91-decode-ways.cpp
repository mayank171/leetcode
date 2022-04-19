class Solution {
private:
    
//     int check(string &s,int n,vector<int> &dp)
//     {
        
//         if(n==0)
//         {
//             return dp[n]=1;
//         }
        
//         if(dp[n]!=-1)
//             return dp[n];
        
//         int ct=0;
//         if(s[n-1]!='0')
//         {
//             ct+=check(s,n-1,dp);
//         }
        
//         if(n>1 && stoi(s.substr(n-2,2))>=10 && stoi(s.substr(n-2,2))<=26)
//         {
//             ct+=check(s,n-2,dp);
//         }
        
//         return dp[n]=ct;
//     }
    
    
    int check(int ind,int n,string &s,vector<int> &dp)
    {
        if(ind==n)
        {
            return dp[n]=1;
        }
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int ct=0;
    
        if(s[ind]!='0')
        {
            ct+=check(ind+1,n,s,dp);
        }
        else
        {
            return dp[ind]=0;
        }
        
        if(ind+1<n && (s[ind]-'0')*10+(s[ind+1]-'0')>0 && (s[ind]-'0')*10+(s[ind+1]-'0')<=26)
        {
            ct+=check(ind+2,n,s,dp);
        }
       
        return dp[ind]=ct;
    }
    
public:
    int numDecodings(string s) {
        
//         int l=s.length();
        
//         vector<int> dp(l+1,-1);
        
//         int ans=check(s,l,dp);
        
        
//         for(auto &it:dp)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         return ans;
        
        
        int n=s.length();
        
        vector<int> dp(n+1,-1);
        
        int ind=0;
        
        check(ind,n,s,dp);
        
        
        for(auto &it:dp)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        
        return dp[0];
    }
};