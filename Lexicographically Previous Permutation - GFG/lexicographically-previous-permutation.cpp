// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string prevPermutation(string s) {
        // code here
        int index=-1;
        int l=s.length();
        
        for(int i=1;i<l;i++)
        {
            if(s[i-1]>s[i])
            {
                index=i;
            }
        }
        
        if(index==-1)
            return "None";
        
            
        int lastInd=-1;
        for(int i=index+1;i<l;i++)
        {
            if(s[index-1]<=s[i])
            {
                lastInd=i;
                break;
            }
        }
        
        if(lastInd==-1)
        {
            swap(s[index-1],s[l-1]);
            reverse(s.begin()+index,s.end());
            return s;
            
        }
        
        swap(s[index-1],s[lastInd-1]);
        reverse(s.begin()+index,s.end());
        
        return s;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout<<ob.prevPermutation(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends