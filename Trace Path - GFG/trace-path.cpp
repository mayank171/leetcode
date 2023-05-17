//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        
       int tr=0;
       int tl=0;
       int cur=0;
       int l=s.length();
       
       for(int i=0;i<l;i++)
       {
           if(s[i]=='L')
           {
               cur++;
               tl=max(tl,cur);
           }
           else if(s[i]=='R')
           {
               cur--;
               tr=min(tr,cur);
           }
           
           if(tl-tr>=m)
              return 0;
       }
       
       int tu=0;
       int td=0;
       cur=0;
       
       for(int i=0;i<l;i++)
       {
           if(s[i]=='U')
           {
               cur++;
               tu=max(tu,cur);
           }
           else if(s[i]=='D')
           {
               cur--;
               td=min(td,cur);
           }
           
           if(tu-td>=n)
              return 0;
       }
       
       return 1;
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends