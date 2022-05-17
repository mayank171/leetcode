// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        if(n==1 || n==2)
          return false;
          
        sort(A,A+n);
        
        set<int> st;
        
        for(int i=0;i<n;i++)
        {
            int target=X-A[i];
            
            if(st.find(target)!=st.end())
               return true;
             
            for(int j=0;j<i;j++)
            {
                st.insert(A[i]+A[j]);
            }
        }
        
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends