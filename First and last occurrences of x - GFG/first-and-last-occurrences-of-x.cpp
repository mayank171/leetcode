//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int ind1=lower_bound(arr,arr+n,x)-arr;
    int ind2=upper_bound(arr,arr+n,x)-arr;
    
    if(ind1==n || ind2-1<0 || ind1==ind2)
    {
        return {-1,-1};
    }
    
    return {ind1,ind2-1};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends