//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
  
    long long solve(vector<int> &v,int ind,int last,vector<vector<long long>> &dp)
    {
        if(ind<0)
           return 0;
           
        if(dp[ind][last]!=-1)
           return dp[ind][last];
        
       if(last==0)
        {
            long long x=v[ind];
            x+=solve(v,ind-1,1,dp);
            return dp[ind][last]= x;
        }
        else
        {
            long long take=v[ind];
            take+=solve(v,ind-1,1,dp);
            long long nottake=solve(v,ind-1,0,dp);
            
            return dp[ind][last]=max<long long>(take,nottake);
        }
    }
  
    long long findMaxSubsetSum(int N, vector<int> &A) {
        
        int last=2;
        vector<vector<long long>> dp(N+1,vector<long long> (last+1,-1));
        return solve(A,N-1,last,dp);
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends