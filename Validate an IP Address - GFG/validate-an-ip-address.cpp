//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            
            if(s[s.length()-1]=='.' || s[0]=='.')
               return 0;
            
            vector<string> str;
            
            for(int i=0;i<s.length();i++)
            {
                int j=i;
                string k="";
                int flag=0;
                while(j<s.length() && s[j]>='0' && s[j]<='9')
                {
                    flag=1;
                    k+=s[j];
                    j++;
                }
                
                if(flag==0)
                   return 0;
                   
                str.push_back(k);
                i=j;
            }
            
            
            // for(auto &it:str)
            // {
            //     cout<<it<<" ";
            // }
            // cout<<endl;


            if(str.size()==4)
            {
                for(int i=0;i<4;i++)
                {
                    long long k=0;
                    int j=0;
                    while(j<str[i].length())
                    {
                        k=k*10+(str[i][j]-'0');
                        j++;
                    }

                    if(k<0 || k>255)
                    {
                        return 0; 
                    }
                    if(str[i][0]=='0' && k!=0)
                    {
                        return 0;
                    }
                    if(str[i][0]=='0' && str[i].length()>1)
                    {
                        return 0;
                    }
                    
                }
                return 1;
            }
            return 0;
            
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends