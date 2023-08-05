//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    void solve(int n,int a,int b,int c,long long &ans)
    {
        if(n==0)
        {
            return ;
        }
        
        solve(n-1,a,c,b,ans);
        ans++;
        cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<b<<endl;
        solve(n-1,c,b,a,ans);
    }
    
    long long toh(int N, int from, int to, int aux) {
        
        long long ans=0;
        solve(N,from,to,aux,ans);
        
        return ans;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends