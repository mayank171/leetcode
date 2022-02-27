// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    bool isPalindrome(string s)
    {
    
        int l=s.length();
        for(int i=0;i<l/2;i++)
        {
            if(s[i]!=s[l-i-1])
            {
                return false;
            }
        }
        
        return true;
    }
    void check(string s,vector<vector<string>> &ans,vector<string> &temp)
    {
        if(s.empty())
        {
            ans.push_back(temp);
        }
        
        for(int i=0;i<s.length();i++)
        {
            string s1=s.substr(0,i+1);
            if(isPalindrome(s1))
            {
                temp.push_back(s1);
                string s2=s.substr(i+1,s.length());
                check(s2,ans,temp);
                temp.pop_back();
            }
        }
    }
    
  public:
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;

        vector<string> temp;
        
        check(S,ans,temp);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends