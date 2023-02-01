//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    long long int solve(int n,vector<int> colors[],int lastColor,int ind,vector<vector<long long int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        
        if(dp[ind][lastColor+1]!=-1)
           return dp[ind][lastColor+1];
        
        long long int mini=1e12;
        for(int i=0;i<3;i++)
        {
            if(i!=lastColor)
            {
                mini=min<long long>(mini,colors[i][ind]+solve(n,colors,i,ind+1,dp));
            }
        }
        
        return dp[ind][lastColor+1]=mini;
    }

    long long int distinctColoring(int N, int r[], int g[], int b[]){
        
        vector<int> colors[3];
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i==0)
                   colors[i].push_back(r[j]);
                else if(i==1)
                   colors[i].push_back(g[j]);
                else if(i==2)
                   colors[i].push_back(b[j]);
            }
        }
        
        vector<vector<long long int>> dp(N,vector<long long int> (4,-1));
        
        return solve(N,colors,-1,0,dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends