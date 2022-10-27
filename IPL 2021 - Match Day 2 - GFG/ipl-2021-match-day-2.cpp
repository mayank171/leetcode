// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
    void buildTree(vector<int> &seg,vector<int> &arr,int ss,int se,int si)
    {
        if(ss==se)
        {
            seg[si]=arr[ss];
            return ;
        }
        
           
        int mid=(ss+se)/2;
        
        buildTree(seg,arr,ss,mid,2*si+1);
        buildTree(seg,arr,mid+1,se,2*si+2);
        
        seg[si]=max(seg[2*si+1],seg[2*si+2]);
    }
    
    int query(vector<int> &seg,vector<int> &arr,int ss,int se,int si,int qs,int qe)
    {
        if(qs>se || qe<ss)
           return -1e8;
           
        if(ss>=qs && se<=qe)
        {
            return seg[si];
        }
        
        int mid=(ss+se)/2;
        
        int l=query(seg,arr,ss,mid,2*si+1,qs,qe);
        int r=query(seg,arr,mid+1,se,2*si+2,qs,qe);
        
        return max(l,r);
    }
  
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
       vector<int> seg(n*4,-1);
       buildTree(seg,arr,0,n-1,0);
       
       vector<int> ans;
       
       for(int i=0;i<n-k+1;i++)
       {
           int qs=i;
           int qe=i+k-1;
           
           ans.push_back(query(seg,arr,0,n-1,0,qs,qe));
       }
       
       return ans;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends