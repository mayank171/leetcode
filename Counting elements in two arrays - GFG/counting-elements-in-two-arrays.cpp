//{ Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
  
    int solve(int arr[],int val,int n)
    {
        int low=0;
        int high=n-1;
        int ind=-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]>val)
            {
                high=mid-1;
            }
            else
            {
                ind=mid;
                low=mid+1;
            }
        }
        
        return ind+1;
    }
  
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[],int m, int n)
    {
        vector<pair<int,int>> a;
        for(int i=0;i<m;i++)
        {
            a.push_back({arr1[i],i});
        }
        
        sort(a.begin(),a.end());
        sort(arr2,arr2+n);
        vector<int> ans(m);
        
        
        
        for(int i=0;i<m;i++)
        {
            int x=solve(arr2,a[i].first,n);
            ans[a[i].second]=x;
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
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends