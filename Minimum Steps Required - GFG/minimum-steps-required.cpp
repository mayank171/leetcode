//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    
    int n=str.length();
    
    int ct=0;
    
    if(str[0]=='a')
    {
        for(int i=1;i<n;i++)
        {
            if(str[i]=='b')
            {
                int start=i;
                while(start<n && str[start]==str[start+1])
                {
                    start++;
                }
                
                ct++;
                i=start;
            }
        }
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            if(str[i]=='a')
            {
                int start=i;
                while(start<n && str[start]==str[start+1])
                {
                    start++;
                }
                
                ct++;
                i=start;
            }
        }
    }
    
    return ct+1;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends