//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int solve(string &str1,string &str2,int ind1,int ind2,int m)
    {
        if(ind1<0)
        {
            if(ind2<0)
               return 1;
            return 0;
        }
        
        if(ind2<0)
        {
            return 1;
        }
     
        int l=0;   
        if(str1[ind1]==str2[ind2])
        {
           str1[ind1]='0';
           int x=solve(str1,str2,ind1-1,ind2-1,m);
           if(x!=0 && ind2==m-1)
              l=1+solve(str1,str2,ind1-1,ind2,m);
           else if(x!=0 && ind2<m-1)
           {
               return 1;
           }
        }
            
        int r= solve(str1,str2,ind1-1,ind2,m);
        
        return l+r;
    }

    int numberOfSubsequences(string S, string W){
        // code here 
        int n=S.length();
        int m=W.length();
        
        
        return solve(S,W,n-1,m-1,m);
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