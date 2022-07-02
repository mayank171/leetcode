// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(vector<vector<int>> &dp,vector<int> arr,int sum,int ind,int n)
    {
        if(ind==0)
        {
            if(arr[ind]==sum)
               return true;
            return false;
        }
        
        if(dp[ind][sum]!=-1)
           return dp[ind][sum];
        
        int take=0;
        if(arr[ind]<=sum)
        {
            take=check(dp,arr,sum-arr[ind],ind-1,n);
        }
        int notTake=check(dp,arr,sum,ind-1,n);
        
        return dp[ind][sum]=take|notTake;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        //return check(dp,arr,sum,n-1,n);
        
        vector<int> front(sum+1,0);
        front[0]=1;
        if(arr[0]<sum)
           front[arr[0]]=1;
           
        for(int i=1;i<n;i++)
        {
            vector<int> cur(sum+1,0);
            cur[0]=1;
            for(int j=1;j<=sum;j++)
            {
                int notTake=front[j];
                int take=0;
                if(arr[i]<=j)
                   take=front[j-arr[i]];
                cur[j]=take|notTake;
            }
            front=cur;
        }
        
        return front[sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends