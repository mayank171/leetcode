//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      
      
      vector<pair<int,int>> v1;
      vector<pair<int,int>> v2;
      
      for(int i=0;i<n;i++)
      {
          if(arr[i]<0)
            v2.push_back({abs(arr[i]),i});
          else
            v1.push_back({arr[i],i});
      }
      
      long long ans=0;
      
      int i=0;
      int j=0;
      
      while(true)
      {
          if(i==v1.size() && j==v2.size())
             break;
          
          if(v1[i].first<v2[j].first)
          {
              v2[j].first=(v2[j].first-v1[i].first);
              ans+=v1[i].first*(abs(v1[i].second-v2[j].second));
              i++;
          }
          else if(v1[i].first>v2[j].first)
          {
              v1[i].first=(v1[i].first-v2[j].first);
              ans+=v2[j].first*(abs(v1[i].second-v2[j].second));
              j++;
          }
          else
          {
              ans+=v1[i].first*(abs(v1[i].second-v2[j].second));
              v1[i].first=0;
              v2[j].first=0;
              
              i++;
              j++;
          }
          
         // cout<<ans<<endl;
      }
      
      return ans;
      
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends