//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        
        string ans="";
        
        int maxl=max(X.length(),Y.length());
     //   cout<<maxl<<endl;
        
        
        int carry=0;
        int i=X.length()-1;
        int j=Y.length()-1;
        
        while(i>=0 && j>=0)
        {
            int x=(X[i]-'0')+(Y[j]-'0')+carry;
         //   cout<<X[i]<<" "<<Y[j]<<endl;
            ans.push_back((x%10)+'0');
            carry=x/10;
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int x=(X[i]-'0')+carry;
            ans.push_back((x%10)+'0');
            carry=x/10;
            i--;
        }
        
        while(j>=0)
        {
            int x=(Y[j]-'0')+carry;
            ans.push_back((x%10)+'0');
            carry=x/10;
            j--;
        }
        
        if(carry>0)
        {
            ans.push_back(carry+'0');
        }
        
        reverse(ans.begin(),ans.end());
        
        
        reverse(ans.begin(),ans.end());
        
        while(ans.back()=='0')
           ans.pop_back();
        
        reverse(ans.begin(),ans.end());
        
        if(ans.size()==0)
           return "0";
        
        return ans;
    }
};










//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends