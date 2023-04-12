//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        
        sort(arr.begin(),arr.begin()+n/2);
        sort(arr.begin()+n/2,arr.begin()+n,greater<int>());
        
        // for(auto &it:arr)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        int ct=0;
        int i=0;
        for(int j=n/2;j<n;j++)
        {
            int ind=lower_bound(arr.begin(),arr.begin()+n/2,5*arr[j])-arr.begin();
           // cout<<ind<<endl;
            if(ind==n/2)
            {
                continue;
            }
            else
            {
                //cout<<"+"<<n/2-ind<<" "<<n-j<<endl;
                ct+=(n/2-ind);
            }
        }
        
        // cout<<ct<<endl;
        
        return ct;
        
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends