//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

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
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    int sum=accumulate(A,A+N,0);
    
    int ans=0;
    for(int i=0;i<N;i++)
    {
        ans+=A[i]*i;
    }
    
    int res=ans;
    int ind=N-1;
    for(int i=0;i<N-1;i++)
    {
        int x=sum-A[ind]*(N-1)-A[ind];
        ans+=x;
        res=max(res,ans);
       // ans=res;
        ind--;
    }
    
    return res;
}