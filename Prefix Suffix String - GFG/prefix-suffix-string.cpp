//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool ispossible(string &s,string &t)
    {
        int n = s.size();
        int m = t.size();
        if(n<m) return false;
        bool flag = true;
        for(int i=0;i<m;i++)
        {
            if(s[i]!=t[i]) 
            {
                flag = false;
                break;
            }
        }
        if(flag) return true;
        int i=m-1;
        int j=n-1;
        bool flag2 = true;
        while(i>=0)
        {
            if(s[j]!=t[i])
            {
                flag2 = false;
                break;
            }
            i--;
            j--;
        }
        if(flag2) return true;
        return false;
    }
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        int count=0;
        int n2 = s2.size();
        int n1 = s1.size();
        for(int i=0;i<n2;i++)
        {
            for(int j=0;j<n1;j++)
            {
                if(ispossible(s1[j],s2[i])) 
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends