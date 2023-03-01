//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
         int slen=S.length();
        int tl=T.length();
        
        int sind=0;
        
        for(int i=0;i<tl;i++)
        {
            if(T[i]>='0' && T[i]<='9')
            {
                int k=0;
                int j=i;
                while(j<tl && T[j]>='0' && T[j]<='9')
                {
                    k=k*10+(T[j]-'0');
                    j++;
                }
               // cout<<k<<endl;
                sind=sind+k;  
                i=j-1;
            }
            else 
            {
                if(S[sind]!=T[i])
                   return 0;
                sind++;
            }
        }
   
       // cout<<sind<<endl;     
        if(sind==slen)
           return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends