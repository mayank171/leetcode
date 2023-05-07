//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]<b[0])
           return true;
        else if(a[0]==b[0])
        {
            if(a[1]<b[1])
               return true;
        }
        
        return false;
    }

    int maxCoins(int n,vector<vector<int>> &ranges){
        
        sort(ranges.begin(),ranges.end(),comp);
        
        vector<int> post(n);
        post[n-1]=ranges[n-1][2];
        
        for(int i=n-2;i>=0;i--)
        {
            post[i]=max(post[i+1],ranges[i][2]);
        }
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            int cost1=ranges[i][2];
            
            int low=i+1;
            int high=n-1;
            int ans=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                
                if(ranges[mid][0]>=ranges[i][1])
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            
            if(ans!=-1)
            {
                int cost2=post[ans];
                res=max(res,cost1+cost2);
            }
            else
            {
                res=max(res,cost1);
            }
        }
        
        return res;
    }
};



















//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends