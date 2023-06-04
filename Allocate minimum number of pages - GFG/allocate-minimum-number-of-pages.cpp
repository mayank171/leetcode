//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    int blackBox(int a[],int n,int m,int mid)
    {
        int maxi=0;
        int sum=0;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(sum+a[i]>mid)
            {
                ct++;
                sum=a[i];
                if(sum>mid)
                   return 1;
            }
            else
            {
                sum+=a[i];
            }
        }
        
        if(sum>0)
        {
            ct++;
        }
     
        if(ct>m)
          return 1;
        return 0;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
           return -1;
        
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
        }
       // cout<<sum<<endl;
        
        int low=1;
        int high=sum;
        
        int ans=1e9;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            int k=blackBox(A,N,M,mid);
           
            if(k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends