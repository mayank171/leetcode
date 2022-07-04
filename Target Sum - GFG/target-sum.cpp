// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int sum=accumulate(A.begin(),A.end(),0);
        
        if((sum-target)&1 || sum-target<0)
          return 0;
          
        int n=A.size();
        
        sum=(sum-target)/2;
        
        vector<int> front(sum+1,0);
        if(A[0]==0)  front[0]=2;
        else   front[0]=1;
        
        if(A[0]!=0 && A[0]<sum+1)
          front[A[0]]=1;
          
        for(int i=1;i<n;i++)
        {
            vector<int> cur(sum+1,0);
            for(int j=0;j<sum+1;j++)
            {
                int take=0;
                if(A[i]<=j)
                {
                    take=front[j-A[i]];
                }
                int notTake=front[j];
                cur[j]=take+notTake;
            }
            front=cur;
        }
     
        return front[sum];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends