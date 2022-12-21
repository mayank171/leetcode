//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string s, vector<string> &wordDict) {
        //code here
        int l=s.length();
        int n=wordDict.size();
        //sort(wordDict.begin(),wordDict.end());
        vector<int> dp(l+1,0);
        dp[l]=1;

        for(int i=l-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(i+wordDict[j].size()-1<l)
                {
                    string str=s.substr(i,wordDict[j].size());
                   // cout<<str<<endl;
                    int flag=0;
                    for(int k=0;k<str.length();k++)
                    {
                        if(str[k]!=wordDict[j][k])
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        dp[i]=dp[i+wordDict[j].size()];
                    }

                    if(dp[i]==1)
                      break;
                }
            }
        }

        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends