//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        
        string temp="";
        set<char> st;
        for(int i=0;i<str.size();i++)
        {
            
            if((str[i]==temp[temp.size()-1] && st.size()==1))
            {
                break;
            }
            else if((temp.size()==0 || str[i]<=temp[temp.size()-1]))
            {
                temp+=str[i];
                st.insert(str[i]);
            }
            else
               break;
        }
        
        string x=temp;
        reverse(temp.begin(),temp.end());
        x+=temp;
        
        return x;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends