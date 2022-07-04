// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> front(W+1,0);
       
       for(int i=wt[0];i<W+1;i++)
       {
           front[i]=val[0];
       }
       
       for(int i=1;i<n;i++)
       {
           //vector<int> cur(W+1,0);
           for(int j=W;j>=0;j--)
           {
               int notTake=front[j];
               int take=-1e8;
               if(wt[i]<=j)
               {
                   take=val[i]+front[j-wt[i]];
               }
               front[j]=max(take,notTake);
           }
           //front=cur;
       }
       
       return front[W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends