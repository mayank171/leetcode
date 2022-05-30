// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> ans;
       
       for(int i=0;i<n;i++)
       {
           int size=ans.size();
           if(size==0)
           {
               ans.push_back(a[i]);
           }
           else
           {
               if(a[i]>ans[size-1])
               {
                   ans.push_back(a[i]);
               }
               else
               {
                   int ind=upper_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                   if(ind==size)
                   {
                       continue;
                   }
                   else if(ind-1>=0 && ans[ind-1]==a[i])
                   {
                       continue;
                   }
                   else
                   {
                       ans[ind]=a[i];
                   }
               }
           }
           
       }
       
       return ans.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends