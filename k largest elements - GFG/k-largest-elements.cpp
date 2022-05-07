// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
private:
    void heapify(vector<int> &v,int size,int i)
    {
        int small=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<size && v[small]>v[left])
            small=left;
        if(right<size && v[small]>v[right])
            small=right;
        if(small!=i)
        {
            swap(v[small],v[i]);
            heapify(v,size,small);
        }
    }
    
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> v(k);
	    
	    for(int i=0;i<k;i++)
	    {
	        v[i]=arr[i];
	    }
	    
	    for(int i=k/2;i>=0;i--)
	    {
	        heapify(v,k,i);
	    }
	    
	    for(int i=k;i<n;i++)
	    {
	        if(arr[i]>v[0])
	        {
	            v[0]=arr[i];
	            heapify(v,k,0);
	        }
	    }
	    
	   // for(auto &it:v)
	   // {
	   //     cout<<it<<" ";
	   // }
	   // cout<<endl;
	    
	    sort(v.rbegin(),v.rend());
	    
	    return v;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends