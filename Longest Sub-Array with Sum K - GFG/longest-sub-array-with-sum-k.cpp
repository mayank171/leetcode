//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int K) 
    { 
        
        for(int i=1;i<n;i++)
        {
            A[i]=A[i]+A[i-1];
        }
        
        int ans=0;
        
        map<int,int> mp;
        mp[0]=-1;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(A[i]-K)!=mp.end())
            {
                ans=max(ans,i-mp[A[i]-K]);
            }
            if(mp.find(A[i])==mp.end())
            {
                mp[A[i]]=i;
            }
            
        }
        
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends