// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends

vector<int> vp(1e7,INT_MAX);
  
void build(int arr[],vector<int> &vp,int si,int ss,int se)
{
    
    
    if(ss==se)
    {
        vp[si]=arr[ss];
        return;
    }
    
    int mid=(ss+se)/2;
    
    build(arr,vp,2*si+1,ss,mid);
    build(arr,vp,2*si+2,mid+1,se);
    
    vp[si]=min(vp[2*si+1],vp[2*si+2]);
}

int query(int qs,int qe,int si,int ss,int se)
{
    if(qs>se || qe<ss)
       return INT_MAX;
    
    if(qs<=ss && se<=qe)
       return vp[si];
       
    int mid=(ss+se)/2;
    
    int l=query(qs,qe,2*si+1,ss,mid);
    int r=query(qs,qe,2*si+2,mid+1,se);
    
    return min(l,r);
}

/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
  //Your code here
  
  
  build(arr,vp,0,0,n-1);
  
  
  
}


/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
   int ans=query(a,b,0,0,n-1);
   return ans;
}