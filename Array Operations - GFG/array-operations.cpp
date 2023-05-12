//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                flag=1;
            }
        }
        
        if(flag==0)
           return 1;
        
        int ct=0;
        int i=-1;
        int j=-1;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            while(i<n-1)
            {
                flag1=1;
                i++;
                if(arr[i]==0)
                  break;
            }
            
            while(j<i)
            {
                flag2=1;
                if(i-j>1)
                   ct++;
                else if(i-j==1 && arr[i]!=0)
                   ct++;
                j=i;
            }
            
            if(flag1==0 && flag2==0)
               break;
        }
        
        return ct;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends