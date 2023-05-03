//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n-1,vector<int> (n-1,0));
        
        for(int gap=0;gap<n-1;gap++)
        {
            for(int i=0,j=gap;j<n-1;i++,j++)
            {
                if(gap==0)
                {
                    dp[i][j]=0;
                }
                else if(gap==1)
                {
                    dp[i][j]=arr[i]*arr[j]*arr[j+1];
                }
                else
                {
                    int mini=1e9;
                    for(int k=i;k<j;k++)
                    {
                        int x=dp[i][k];
                        int y=dp[k+1][j];
                        int z=arr[i]*arr[k+1]*arr[j+1];
                       // cout<<k<<" "<<x<<" "<<y<<" "<<z<<endl;
                        mini=min(mini,x+y+z);
                    }
                    dp[i][j]=mini;
                }
            }
        }
        
        // for(auto &it:dp)
        // {
        //     for(auto &it1:it)
        //     {
        //         cout<<it1<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[0][n-2];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends