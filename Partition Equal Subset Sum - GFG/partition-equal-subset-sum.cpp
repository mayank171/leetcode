// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=accumulate(arr,arr+n,0);
        
        if(sum&1)
          return 0;
          
         sum=sum/2;
          
        
        vector<bool> front(sum+1,false);
        front[0]=true;
        if(arr[0]<=sum)
           front[arr[0]]=true;
        
        
        for(int i=1;i<n;i++)
        {
            vector<bool> cur(sum+1,false);
            cur[0]=true;
            for(int j=1;j<sum+1;j++)
            {
                bool notTake=front[j];
                bool take=false;
                if(arr[i]<=j)
                {
                    take=front[j-arr[i]];
                }
                cur[j]=take|notTake;
            }
            front=cur;
        }
        
        if(front[sum]==true)
        return true;
        
        return false;
    }
};

// { Driver Code Starts.

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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends