//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<int> &coins,int n,int k,int target,vector<int> &freq,vector<vector<int>> &dp)
    {
        if(target<0)
           return 0;
        if(target==0)
        {
            if(k==0)
               return 1;
            return 0;
        }
        
        if(dp[target][k]!=-1)
           return dp[target][k];
        
        for(int i=0;i<n;i++)
        {
            if(target>=coins[i])
            {
                if(solve(coins,n,k-1,target-coins[i],freq,dp))
                   return dp[target][k]=1;
            }
            else
                break;
        }
        
        return dp[target][k]=0;
    }
  
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        
        sort(coins.begin(),coins.end());
        vector<int> freq(N,K);
        vector<vector<int>> dp(target+1,vector<int>(K+1,-1));
        return solve(coins,N,K,target,freq,dp);
        // vector<int> dp(target+1,0);
        // vector<map<int,int>> temp(target+1);
        // map<int,int> mp;
        // mp[0]=1;
        // temp[0]=mp;
        
        // for(int i=1;i<target+1;i++)
        // {
        //     for(int j=0;j<N;j++)
        //     {
        //         if(i-coins[j]>=0)
        //     }
        // }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends