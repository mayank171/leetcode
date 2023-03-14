//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int maxCoins(int N, vector <int> &a)
        {
            vector<vector<int>> dp(N,vector<int> (N,0));
                
            for(int gap=0;gap<N;gap++)
            {
                for(int i=0,j=gap;j<N;j++,i++)
                {
                   
                    int maxi=0;
                    for(int k=i;k<=j;k++)
                    {
                        int left= (k==i)?0:dp[i][k-1];
                        int right= (k==j)?0:dp[k+1][j];
                    
                        int x=(i-1>=0?a[i-1]:1)*a[k]*(j+1<N?a[j+1]:1);
                        maxi=max(maxi,x+left+right);
                    }
                    
                    dp[i][j]=maxi;
                }
            }
            
            // for(int i=0;i<N;i++)
            // {
            //     for(int j=0;j<N;j++)
            //     {
            //         cout<<dp[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            
            return dp[0][N-1];
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends