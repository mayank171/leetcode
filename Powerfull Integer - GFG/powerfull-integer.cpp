//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[intervals[i][0]]++;
            mp[intervals[i][1]+1]--;
        }
        
        int maxi=-1;
        int sum=0;
        for(auto &it:mp)
        {
            // if(it.second<0)
            // {
            //     if(sum>=k)
            //     {
            //         maxi=max(maxi,it.first-1);
            //     }
            //     sum+=it.second;
            // }
            // else
            
            if(sum>=k)
               maxi=max(maxi,it.first-1);
            sum+=it.second;
        }
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends