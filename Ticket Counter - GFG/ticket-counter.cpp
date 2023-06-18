//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        
        int low=1;
        int high=N;
        
        
        
        int flag=0;
        while(low<=high)
        {
         //   cout<<low<<" "<<high<<endl;
            if(high-low+1<=K)
            {
                if(flag==0)
                   return high;
                else
                   return low;
            }
            
            if(flag==0)
               low+=K;
            else
               high-=K;
            flag=1-flag;
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends