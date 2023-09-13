//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        
        string s="";
        
        int flag=0;
        int NN=N;
        
        while(N--)
        {
    
            
            if(S<10)
            {
                s+=(S+'0');
                S=0;
                flag=1;
                break;
            }
            else 
            {
                s+='9';
                S-=9;
            }
        }
        
        if(flag==1)
        {
            while(N--)
            {
                s+='0';
            }
        }
        
        if((s[0]=='0' && NN>1)  || S>0)
        {
            return "-1";
        }
        
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends