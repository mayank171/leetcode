//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    void buildTree(int *arr,vector<int> &seg,int ss,int se,int si)
    {
        
        if(ss==se)
        {
            seg[si]=arr[ss];
            return ;
        }
        
        int mid=se-(se-ss)/2;
        buildTree(arr,seg,ss,mid-1,2*si+1);
        buildTree(arr,seg,mid,se,2*si+2);
        
        seg[si]=max(seg[2*si+1],seg[2*si+2]);
    }
    
    int query(int *arr,vector<int> &seg,int ss,int se,int si,int qs,int qe)
    {
        if(qe<ss || qs>se)
        {
            return INT_MIN;
        }
        
        if(ss>=qs && se<=qe)
        {
            return seg[si];
        }
        
        int mid=se-(se-ss)/2;
        
        int l=query(arr,seg,ss,mid-1,2*si+1,qs,qe);
        int r=query(arr,seg,mid,se,2*si+2,qs,qe);
        
        return max(l,r);
    }
    
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
    //     vector<int> seg(4*n,-1);
    //     buildTree(arr,seg,0,n-1,0);
        
    //   // return {};
        
    //     vector<int> ans;
        
    //     for(int i=0;i<=n-k;i++)
    //     {
    //         int qs=i;
    //         int qe=i+k-1;
            
    //         ans.push_back(query(arr,seg,0,n-1,0,qs,qe));
    //         //break;
    //     }
        
    //     return ans;
    
     
       vector<int> nse(n,n);
       
       stack<int> stk;
       
       for(int i=0;i<n;i++)
       {
           if(!stk.empty())
           {
               if(arr[stk.top()]<arr[i])
               {
                   while(!stk.empty() && arr[stk.top()]<arr[i])
                   {
                       nse[stk.top()]=i;
                       stk.pop();
                   }
                   stk.push(i);    
               }
               else
               {
                   stk.push(i);
               }
           }
           else
           {
               stk.push(i);
           }
       }
       
    //   for(auto &it:nse)
    //   {
    //       cout<<arr[it]<<" ";
    //   }
    //   cout<<endl;
       
       vector<int> ans(n-k+1);
       
       int i=0;
       int j=0;
       
       while(i<=n-k)
       {
           if(j<i)
           {
               j=i;
           }
           
           while(nse[j]<=(i+k-1))
           {
               j=nse[j];
           }
           
           ans[i]=arr[j];
           i++;
       }
       
       return ans;
    }
};
































//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends