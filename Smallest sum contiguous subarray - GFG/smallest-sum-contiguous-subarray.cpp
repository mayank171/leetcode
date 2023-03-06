//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& v){
      //Code here
      int minsum=v[0];
      int cursum=v[0];
      
      for(int i=1;i<v.size();i++)
      {
          if(cursum>0)
          {
              cursum=0;
          }
          cursum+=v[i];
          minsum=min(minsum,cursum);
      }
      
      return minsum;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends