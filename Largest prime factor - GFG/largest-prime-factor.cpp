//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        
        vector<long long> ans;
        
        for(int i=2;i*i<=N;i++)
        {
            int x=N;
            while(N%i==0)
            {
                ans.push_back(i);
                N=N/i;
            }
        }
        
        if(N>1)
        {
            ans.push_back(N);
        }
        
        long long maxi=0;
        for(int i=0;i<ans.size();i++)
        {
            maxi=max<long long>(maxi,ans[i]);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends