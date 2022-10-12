//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int offerings(int N, int arr[]){
        
        
        vector<int> front(N,0);
        front[0]=1;
        for(int i=1;i<N;i++)
        {
            if(arr[i]<=arr[i-1])
            {
                front[i]=1;
            }
            else
            {
                front[i]=1+front[i-1];
            }
        }
        
        vector<int> back(N,0);
        back[N-1]=1;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]<=arr[i+1])
            {
                back[i]=1;
            }
            else
            {
                back[i]=1+back[i+1];
            }
        }
        
        int ans=0;
        
        for(int i=0;i<N;i++)
        {
            ans+=max(front[i],back[i]);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.offerings(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends