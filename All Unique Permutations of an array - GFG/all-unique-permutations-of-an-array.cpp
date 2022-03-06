// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void check(vector<int> arr,vector<vector<int>> &ans, vector<int> &temp,int ind, map<int,int> &m)
    {
        if(ind==arr.size())
        {
            ans.push_back(temp);
            return ;
        }
        
        for(auto &it:m)
        {
            if(it.second>0)
            {
                temp.push_back(it.first);
                it.second--;
                
                check(arr,ans,temp,ind+1,m);
                
                it.second++;
                temp.pop_back();
            }
        }
    }
    
  
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {


         map<int,int> m;
         for(int i=0;i<n;i++)
         {
             m[arr[i]]++;
         }
         vector<vector<int>> ans;
        // ans.push_back(arr);
        
        vector<int> temp;
        
        int ind=0;
        
        check(arr,ans,temp,ind,m);
        
         
         return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends