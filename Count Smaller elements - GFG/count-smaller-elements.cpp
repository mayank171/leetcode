//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
    void merge(vector<pair<int,int>> &vp,int low,int mid,int high,vector<int> &ans)
    {
        vector<pair<int,int>> left;
        for(int i=low;i<=mid;i++)
        {
            left.push_back({vp[i].first,vp[i].second});
        }
        
        vector<pair<int,int>> right;
        for(int i=mid+1;i<=high;i++)
        {
            right.push_back({vp[i].first,vp[i].second});
        }
        
        vector<pair<int,int>> temp;
        
        int i=0;
        int j=0;
        
        while(i<left.size() && j<right.size())
        {
            if(left[i].first>right[j].first)
            {
                ans[left[i].second]+=right.size()-j;
                temp.push_back({left[i].first,left[i].second});
                i++;
            }
            else
            {
                temp.push_back({right[j].first,right[j].second});
                j++;
            }
        }
        
        while(i<left.size())
        {
            ans[left[i].second]+=right.size()-j;
            temp.push_back({left[i].first,left[i].second});
            i++;
        }
        
        while(j<right.size())
        {
            //ans[right[i].second]+=right.size()-j;
            temp.push_back({right[j].first,right[j].second});
            j++;
        }
        
        for(int i=0;i<temp.size();i++)
        {
            vp[low+i]=temp[i];
        }
    }
    
    void mergeSort(vector<pair<int,int>> &vp,int l,int h,vector<int> &ans)
    {
        if(l<h)
        {
            int mid=(l+h)/2;
            mergeSort(vp,l,mid,ans);
            mergeSort(vp,mid+1,h,ans);
            merge(vp,l,mid,h,ans);
        }
    }

	vector<int> constructLowerArray(int *arr, int n) {
	    
	    vector<int> ans(n,0);
	    vector<pair<int,int>> vp;
	    
	    for(int i=0;i<n;i++)
	    {
	        vp.push_back({arr[i],i});    
	    }
	    
	    mergeSort(vp,0,n-1,ans);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends