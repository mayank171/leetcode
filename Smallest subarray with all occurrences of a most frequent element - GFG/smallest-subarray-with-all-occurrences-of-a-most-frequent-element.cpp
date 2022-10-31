//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
    	map<int,int> mp;
    	map<int,pair<int,int>> mp1;
    	
    	for(int i=0;i<n;i++)
    	{
    	    mp[a[i]]++;
    	    mp1[a[i]]={-1,-1};
    	}
    	
    	int maxict=0;
    	for(auto &it:mp)
    	{
    	    if(it.second>maxict)
    	    {
    	        maxict=it.second;
    	    }
    	}
    //	cout<<maxict<<endl;
    	
    	vector<int> v;
    	
    	for(auto &it:mp)
    	{
    	    if(it.second==maxict)
    	    {
    	        v.push_back(it.first);
    	    }
    	}
    	
    	for(int i=0;i<n;i++)
    	{
    	    if(mp1[a[i]].first==-1)
    	    {
    	        mp1[a[i]].first=i;
    	        mp1[a[i]].second=i;
    	    }
    	    else
    	    {
    	        mp1[a[i]].second=i;
    	    }
    	}
    	
    	int mini=1e8;
    	for(int i=0;i<v.size();i++)
    	{
    	    mini=min(mini,mp1[v[i]].second-mp1[v[i]].first+1);
    	}
    	
    //	cout<<mini<<endl;
    	
    	int minval=n;
    	for(int i=0;i<n;i++)
    	{
    	    if(mp1.find(a[i])!=mp1.end())
    	    {
    	        if(mp1[a[i]].second-mp1[a[i]].first+1==mini && mp[a[i]]==maxict)
    	        {
    	            minval=a[i];  
    	            break;
    	        }
    	    }
    	    
    	}
    	
    //	cout<<minval<<endl;
    	
    	
    	vector<int> ans;
    	
    	for(int j=mp1[minval].first;j<=mp1[minval].second;j++)
    	{
    	    ans.push_back(a[j]);
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
	    int n,i;
	    cin>>n; int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    vector<int > v;
	    Solution ob;
	    v = ob.smallestSubsegment(a, n);
	    for(int i:v)
	        cout<< i << " ";
	    cout<<"\n";
	}
return 0;
}

// } Driver Code Ends