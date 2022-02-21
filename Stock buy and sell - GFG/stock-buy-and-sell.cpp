// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> ans;
        
        int b=0;
        int s=0;
        for(int i=1;i<n;i++)
        {
            if(A[i]>=A[s])
            {
                s=i;
            }
            else
            {
                vector<int> temp;
                if(b!=s)
                {
                    temp.push_back(b);
                    temp.push_back(s);
                    ans.push_back(temp);
                }
                b=i;
                s=i;
            }
        }
        
         if(b!=s)
         {
             vector<int> temp;
             temp.push_back(b);
             temp.push_back(s);
             ans.push_back(temp);
         }
        
        // for(int i=0;i<ans.size();i++)
        // {
        //     for(int j=0;j<ans[i].size();j++)
        //     {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends