//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
   
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='?')
            {
                if(s[n-i-1]!='?' && s[n-i-1]!=s[i])
                   return -1;
                s[n-i-1]=s[i];
            }
        }
        
   //     cout<<s<<endl;
        
        char prev='?';
        char cur='?';
        int ans=0;
        
        for(int i=0;i<=n/2;i++)
        {
            if(s[i]!='?')
            {
                if(cur=='?' && prev=='?')
                {
                    cur=s[i];
                }
                else if(cur!='?' && prev=='?')
                {
                    prev=cur;
                    cur=s[i];
                }
                else
                {
        //            cout<<prev<<" "<<cur<<endl;
                    ans+=2*abs(cur-prev);
                    prev=cur;
                    cur=s[i];
                }
            }
        }
        
        if(cur!='?' && prev!='?')
            ans+=2*abs(cur-prev);
        
        
        return ans;
        
    //     cout<<s<<endl;
        
    //     char ch='?';
    //     for(int i=n/2-1;i>=0;i--)
    //     {
    //         if(ch=='?' && s[i]!='?')
    //         {
    //             ch=s[i];
    //             //cout<<ch<<endl;
    //         }
    //         else if(ch!='?' && s[i]=='?')
    //         {
    //             s[i]=ch;
    //         }
    //         else if(ch!='?' && s[i]!='?')
    //         {
    //             ch=s[i];
    //         }
    //     }
        
    //   // cout<<s<<endl;
        
    //     ch='?';
    //     for(int i=0;i<n/2;i++)
    //     {
    //         if(ch=='?' && s[i]!='?')
    //         {
    //             ch=s[i];
    //         }
    //         else if(ch!='?' && s[i]=='?')
    //         {
    //             s[i]=ch;
    //         }
    //         else if(ch!='?' && s[i]!='?')
    //         {
    //             ch=s[i];
    //         }
    //     }
        
    //     cout<<s<<endl;
        
    //     if(n&1)
    //     {
    //         for(int i=n/2+1;i<n;i++)
    //         {
    //             s[i]=s[n-i-1];
    //         }
    //     }
    //     else
    //     {
    //         for(int i=n/2;i<n;i++)
    //         {
    //             s[i]=s[n-i-1];
    //         }
    //     }
        
    //     cout<<s<<endl;
        
        
        // int ans=0;
        // for(int i=0;i<n-1;i++)
        // {
        //     ans+=(s[i]-s[i+1]);
        // }
        
        // return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends