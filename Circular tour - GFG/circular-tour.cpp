//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
       vector<int> petrol(n);
       vector<int> dist(n);
       
       int sum1=0;
       int sum2=0;
       for(int i=0;i<n;i++)
       {
           petrol[i]=p[i].petrol;
           dist[i]=p[i].distance;
           sum1+=p[i].petrol;
           sum2+=p[i].distance;
       }
       
       if(sum1<sum2)
       {
           return -1;
       }
       
       int ans=0;
       int ind=-1;
       
       for(int i=0;i<n;i++)
       {
           if(i==0)
           {
               ans+=petrol[i];
               ind=i;
           }
           else
           {
               ans-=dist[i-1];
               
               if(ans<0)
               {
                   ans=petrol[i];
                   ind=i;
               }
               else
               {
                   ans+=petrol[i];
               }
           }
       }
       
       return ind;
       
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends