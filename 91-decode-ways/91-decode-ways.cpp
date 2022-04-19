class Solution {
private:
    
    
    
//     int check(int ind,int n,string &s,vector<int> &dp)
//     {
//         if(ind==n)
//         {
//             return dp[n]=1;
//         }
        
//         if(dp[ind]!=-1)
//             return dp[ind];
        
//         int ct=0;
    
//         if(s[ind]!='0')
//         {
//             ct+=check(ind+1,n,s,dp);
//         }
//         else
//         {
//             return dp[ind]=0;
//         }
        
//         if(ind+1<n && (s[ind]-'0')*10+(s[ind+1]-'0')>0 && (s[ind]-'0')*10+(s[ind+1]-'0')<=26)
//         {
//             ct+=check(ind+2,n,s,dp);
//         }
       
//         return dp[ind]=ct;
//     }
    
public:
    int numDecodings(string s) {
        
        
//         int n=s.length();
        
//         vector<int> dp(n+1,-1);
        
//         int ind=0;
        
//         check(ind,n,s,dp);
        
        
//         for(auto &it:dp)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        
//         return dp[0];
        
        int n=s.length();
        
        vector<int> dp(n+1,-1);
        
        //dp[n]=1;
        
        
    
        for(int i=n;i>=0;i--)
        {
            if(i==n)
            {
                dp[i]=1;
                continue;
            }
            
          
            int ct=0;
            if(s[i]!='0')
            {
                ct+=dp[i+1];
            }
            else
            {
                ct=0;
                dp[i]=ct;
                continue;
            }
            
            if(i+1<n && (s[i]-'0')*10+(s[i+1]-'0')>0 && (s[i]-'0')*10+(s[i+1]-'0')<=26)
            {
                ct+=dp[i+2];
            }
           
            dp[i]=ct;
                
        }
        
        for(auto &it:dp)
        {
            cout<<it<<" ";
        }
        
        
        return dp[0];
        
        
//         for(int i=n-1;i>=0;i--)
//         {
//             if(s[i]>'2')
//             {
//                 dp[i]=dp[i+1];
//             }
//             else if(s[i]=='0')
//             {
//                 continue;
//             }
//             else
//             {
//                 if(i+2>=n+1)
//                 {
//                     dp[i]=dp[i+1];
//                 }
//                 else
//                 {
//                     if(s[i+1]>'6' && s[i]=='2')
//                     {
//                         dp[i]=dp[i+2];
//                     }
//                     else 
//                     {
//                         dp[i]=dp[i+1]+dp[i+2];
//                     }
                    
//                 }
                  
//             }
//         }
        
//         return dp[0];
        
    }
};