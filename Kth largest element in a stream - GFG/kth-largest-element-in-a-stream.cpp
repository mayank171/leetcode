//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void heapify(vector<int> &v,int i,int size)
    {
        int mini=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<size && v[left]<v[mini])
           mini=left;
           
        if(right<size && v[right]<v[mini])
           mini=right;
           
        if(i!=mini)
        {
            swap(v[i],v[mini]);
            heapify(v,mini,size);
        }
    }
  
    vector<int> kthLargest(int k, int arr[], int n) {
        
        vector<int> v;
        for(int i=0;i<k;i++)
        {
            v.push_back(arr[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<k-1;i++)
        {
            ans.push_back(-1);
        }
        
        for(int i=v.size()/2-1;i>=0;i--)
        {
            heapify(v,i,v.size());
        }
        
        for(int i=v.size()-1;i>=0;i--)
        {
            swap(v[0],v[i]);
            heapify(v,i,v.size());
        }
        
        ans.push_back(v[0]);
        
        for(int i=k;i<n;i++)
        {
            if(arr[i]>v[0])
            {
                v[0]=arr[i];
                heapify(v,0,v.size());
            }
                ans.push_back(v[0]);    
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends