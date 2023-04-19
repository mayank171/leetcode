//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        
        vector<int> zero;
        vector<int> ones;
        
        for(int i=0;i<N;i++)
        {
            if(S[i]=='0')
               zero.push_back(i);
            else
               ones.push_back(i);
        }
        
        int i=0;
        int j=0;
        
        while(i<zero.size() && j<ones.size())
        {
            if(abs(zero[i]-ones[j])<=X)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        
        if(i<zero.size())
           return 0;
        return 1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends