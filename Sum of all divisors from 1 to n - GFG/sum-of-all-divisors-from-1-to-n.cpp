//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum=0;
        for(int i=2;i<=N;i++)
        {
            int x=(N/i);
            sum+=(i*x);
        }
        
        sum+=N;
        
        return sum;
    }
};


// 1 2 3 4 5 
// 1 1 1 1 1



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends