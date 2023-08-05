//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    
         long long mini1=1e18;
         long long mini2=1e18;
         long long maxi1=-1e18;
         long long maxi2=-1e18;
         
         sort(a.begin(),a.end());
         long long ans=1e18;
         
         for(int i=0;i<=n-m;i++)
         {
             long long x=a[i];
             long long y=a[i+m-1];
             
             ans=min<long long>(ans,y-x);
         }
         
         return ans;
    }   
};















//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends