//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2){
        
        int l1=s1.length();
        int l2=s2.length();
        
        if(l2>l1)
           return -1;
        
        int mini=1e9;
        for(int i=0;i<=l1-l2;i++)
        {
            int k=i;
            int j=0;
            int ct=0;
            int t=l2;
            string s=s1;
            while(k<l1 && j<l2 && t)
            {
                if(s[k]!=s2[j])
                {
                    s[k]=s2[j];
                    ct++;
                }
                k++;
                j++;
                t--;
            }
            
           // cout<<s<<endl;
            
            int ct2=0;
            int low=i;
            int high=i+l2-1;
            for(int i=0,j=l1-1;i<=j;i++,j--)
            {
                if(s[i]!=s[j])
                {
                    if(i>=low && j<=high)
                    {
                        ct2=1e9;
                        break;
                    }
                    ct2++;
                }
            }
            
           // cout<<ct<<" "<<ct2<<endl;
            
            if(ct2!=1e9)
               mini=min(mini,ct+ct2);
        }
        
        if(mini==1e9)
           return -1;
        
        return mini;
        
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends