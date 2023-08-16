//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
	public:
    long long findNth(long long N)
    {
         vector<int> v;
         while(N)
         {
             v.push_back(N%9);
             N/=9;
         }
         
         long long ans=0;
         long long m=1;
         for(int i=0;i<v.size();i++)
         {
             ans+=(m*1ll*v[i]);
             if(m==0)
             {
                 m=10;
             }
             else
             {
                 m*=10;
             }
         }
         
         return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}


// } Driver Code Ends