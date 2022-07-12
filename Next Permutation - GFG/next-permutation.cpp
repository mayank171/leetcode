// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int index=-1;
        
        for(int i=1;i<N;i++)
        {
            if(arr[i-1]<arr[i])
            {
                index=i;
            }
        }
        
        if(index==-1)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        int lastInd=-1;
        for(int i=index+1;i<N;i++)
        {
            if(arr[index-1]<arr[i])
            {
                lastInd=i;
            }
        }
        
        if(lastInd==-1)
        {
            swap(arr[index],arr[index-1]);
            reverse(arr.begin()+index,arr.end());
            return arr;
        }
        
        swap(arr[index-1],arr[lastInd]);
        reverse(arr.begin()+index,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends