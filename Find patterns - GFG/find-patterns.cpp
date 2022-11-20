//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int solve(string &str1,int ind1,string &str2,int ind2,int m)
    {
        if(ind2<0)
        {
            return 1;
        }
        
        if(ind1<0)
        {
            if(ind2<0)
              return 1;
            return 0;
        }
        
        int x=0;
        if(str1[ind1]==str2[ind2])
        {
            str1[ind1]='0';
            int p=solve(str1,ind1-1,str2,ind2-1,m);
            if(p)
            {
                if(ind2+1!=m)
                   return 1;
                else
                   x=p;
            }
        }
        return x+solve(str1,ind1-1,str2,ind2,m);
        
    }

    int numberOfSubsequences(string S, string W){
        
        
        
        return solve(S,S.length()-1,W,W.length()-1,W.length());
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends