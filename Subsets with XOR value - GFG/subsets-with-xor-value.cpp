//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:

    void solve(vector<int> &arr,int n,int k,int xorr,int ind,int &ct,int flag,vector<int> &temp)
    {
        if(ind==n)
        {
            if(xorr==k)
            {
                // for(auto &it:temp)
                //   cout<<it<<" ";
                // cout<<endl;
                ct++;
            }
            return ;
        }
        
        xorr^=arr[ind];
    //    temp.push_back(arr[ind]);
        solve(arr,n,k,xorr,ind+1,ct,1,temp);
    //    temp.pop_back();
        xorr^=arr[ind];
        solve(arr,n,k,xorr,ind+1,ct,flag,temp);
    }
    
    int subsetXOR(vector<int> arr, int N, int K) {
        
        vector<int> temp;
        int ct=0;
        int flag=0;
        solve(arr,N,K,0,0,ct,flag,temp);
        
        return ct;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends