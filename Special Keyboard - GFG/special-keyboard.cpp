//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // long long solve(int N,int prev,int flag,long long total)
    // {
        
    //     int a=1+solve(N-1,1,flag,total+1);
    //     int b=0;
    //     if(N>=3)
    //     {
    //         b=total+solve(N-3,total,1,total+total);
    //     }
    //     int c=0;
    //     int d=0;
    //     if(flag==1)
    //     {
    //         c=prev+solve(N-1,prev,1,total+prev);
    //         if(N>=3)
    //         {
    //             d=total+solve(N-3,total,1,total+total);
    //         }
    //     }
        
    //     return max<long long>(a,max<long long>(b,max<long long>()))
    // }

    long long int optimalKeys(int N){
    // /    
        long long ans=N;
        
        if(N<=6)
           return N;
        
        vector<int> dp(N+1,0);
        
        for(int i=1;i<=6;i++)
        {
            dp[i]=i;
        }
        
        for(int i=7;i<=N;i++)
        {
            int start=i-3;
            int ct=2;
            long long maxi=0;
            while(start>0)
            {
                maxi=max<long long>(maxi,dp[start]*1ll*ct);
            
                ct++;
                start--;
            }
            
            ans=max<long long>(ans,maxi);
            dp[i]=maxi;
        }
        
        // for(auto &it:dp)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        return ans;
    }
};












//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends