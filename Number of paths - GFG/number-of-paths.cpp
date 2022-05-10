// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    
    // Code Here
     vector<long long> prev(n,0);
	
	for(int i=0;i<m;i++)
	{
		vector<long long> temp(n,0);
		temp[0]=1;
		for(int j=1;j<n;j++)
		{
			temp[j]=temp[j-1]+prev[j];
		}
		prev=temp;
	}
	
	return prev[n-1];
}

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends