//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
        
       int n=x.length();
       
       if(n<2)
          return x[0]-'0';
       
       int num=10*(x[0]-'0')+(x[1]-'0');
       
       int rem=0;
       int ind=2;
       while(true)
       {
           rem=num%11;
           if(rem==0)
           {
                if(ind>=n)
                  return rem;
                else if(ind+1<n)
                  num=10*(x[ind]-'0')+(x[ind+1]-'0');
                else
                  return x[ind]-'0';
                ind+=2;
           }
           else
           {
                if(ind<n)
                {
                    num=rem*10+(x[ind]-'0');
                    ind++;
                }
                else
                {
                    return rem;
                }
           }
       }
       
       return rem;
    }
};









//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends