//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        
        vector<int> temp={1,3,5,7,9};
        
        string ans="";
        while(N)
        {
            int x=N%5;
            if(x==0)
            {
                ans+='9';
            }
            else
            {
                ans+=temp[x-1]+'0';
            }
            N/=5;
            if(N==0)
            {
                break;
            }
            if(x==0 )
            {
                N--;
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        long long a=stoll(ans);
        
        return a;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends