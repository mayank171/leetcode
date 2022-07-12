// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
        int n=str.length();
        string s1=str;
        reverse(str.begin(),str.end());
        string s2=str;
        
        vector<int> front(n+1,0);
        
        for(int i=1;i<n+1;i++)
        {
            vector<int> cur(n+1,0);
            for(int j=1;j<n+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    cur[j]=1+front[j-1];
                }
                else
                {
                    cur[j]=max(front[j],cur[j-1]);
                }
            }
            front=cur;
        }
        
        return n-front[n];
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends