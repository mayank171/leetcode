//{ Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        string ans="";
        while(N)
        {
            int x=N%26;
            //cout<<x<<endl;
            if(x==0)
            {
                ans+='Z';
                N=N/26-1;
            }
            else
            {
                ans+=(x+'A'-1);
                N=N/26;
            }
                
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
    
// } Driver Code Ends